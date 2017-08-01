using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.Sql;
using System.Data.SqlClient;
using System.Threading;

namespace personelTakip
{
    public partial class Form2 : Form
    {
        SqlConnection sCon = new SqlConnection();
        SqlDataAdapter dta = new SqlDataAdapter();
        SqlCommand kayitGetir = new SqlCommand();
        SqlCommand hareket = new SqlCommand();
        DataTable dt = new DataTable();
        delegate void dtSbagla(DataTable dts);
        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            //com porttan sürekli veri beklenir ve bu yüzden port açık değilse açılır
            if (!serialPort1.IsOpen)
                serialPort1.Open();

        }

        private void datagrideDTbagla(DataTable dts)
        {
            //eğer Main thread harici bir thread kontrole(GUI) erişmeye çalışıyorsa
            if (dataGridView1.InvokeRequired)
            {
                //datagrideBagla adındaki metot için delegate örneği oluşturuluyor
                dtSbagla dtbag = new dtSbagla(datagrideDTbagla);
                //nesne referansı üzerinden yeniden tetikleniyor(belirtilen delegate yürütülüyor)
                dataGridView1.Invoke(dtbag, new object[] { dts });
            }
            else
            {
                //aynı iş parçacığından gelen başvurularda doğrudan erişim sağlanıyor
                dataGridView1.DataSource = dts;
                dataGridView1.Refresh();
            }
        }

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            string rfIdKart = serialPort1.ReadLine();
            sCon.ConnectionString = "Server=.\\SQLEXPRESS;initial catalog=personelTakip;Integrated Security=True";

            kayitGetir.CommandType = CommandType.StoredProcedure;
            kayitGetir.Parameters.Add("@rfId", SqlDbType.NVarChar).Value = rfIdKart;      //giriş parametresi 
            kayitGetir.Parameters.Add("@sonuc", SqlDbType.Int).Direction = ParameterDirection.Output;  //çıkış parametresi
            kayitGetir.Connection = sCon;
            kayitGetir.CommandText = "rfIdSorgula";
            sCon.Open();
            kayitGetir.ExecuteNonQuery();

            int kayitVarmi = Convert.ToInt32(kayitGetir.Parameters["@sonuc"].Value);
            kayitGetir.Parameters.Clear();
            sCon.Close();

            if (kayitVarmi > 0)
            {
                serialPort1.WriteLine("A");
                hareket.Connection = sCon;
                hareket.CommandText = "select personel.personelAd,personel.personelSoyad,hareket.tarihSaat from hareket,personel where hareket.personelId=personel.personelId";
                dta.SelectCommand = hareket;
                //DataTable içeriğini temizle
                dt.Clear();
                //DataAdapter nesnesinin içeriğini DataTable'a aktar
                dta.Fill(dt);

                new Thread(new ThreadStart(basla)).Start();
            }
            else
            {
                serialPort1.WriteLine("K");
            }
        }

        void basla()
        {
            datagrideDTbagla(dt);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            serialPort1.Close();
        }

        private void backgroundWorker1_DoWork(object sender, DoWorkEventArgs e)
        {

        }
    }
}
