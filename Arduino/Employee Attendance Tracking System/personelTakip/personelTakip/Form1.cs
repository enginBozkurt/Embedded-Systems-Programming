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
using System.Data.SqlTypes;

namespace personelTakip
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
             System.Windows.Forms.Form.CheckForIllegalCrossThreadCalls = false;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            personelEkle();
        }

        private void label3_Click(object sender, EventArgs e) {

        }

        private void label6_Click(object sender, EventArgs e) {

        }

        private void personelEkle()
        {
            //veri tabanına bağlanmak için connection nesnesi oluştur
            SqlConnection scon = new SqlConnection();

            scon.ConnectionString = "Server=.\\SQLEXPRESS;initial catalog=personelTakip;Integrated Security=True";
            //sql komutlarını çalıştırabilmek için SqlCommand sınıfının bir nesnesini oluştur
            SqlCommand kayitEkle = new SqlCommand();
            //bağlantı özelliğini bir SqlConnection nesnesi olan scon'dan al
            kayitEkle.Connection = scon;

            //sql sorgularında kullanılmak üzere parametre oluştur
            kayitEkle.Parameters.AddWithValue("@personelAd", textBox1.Text);
            kayitEkle.Parameters.AddWithValue("@personelSoyad", textBox2.Text);
            kayitEkle.Parameters.AddWithValue("@tcKimlik", textBox3.Text);
            kayitEkle.Parameters.AddWithValue("@bolum", textBox4.Text);
            kayitEkle.Parameters.AddWithValue("@adres", textBox5.Text);
            kayitEkle.Parameters.AddWithValue("@telefon", textBox6.Text);
            kayitEkle.Parameters.AddWithValue("@rfId", textBox7.Text);
            //parametre olarak verilen kayıtlar veritabanına sql komutuyla eklenir
            kayitEkle.CommandText = "INSERT INTO personel values(@personelAd,@personelSoyad,@tcKimlik,@bolum,@adres,@telefon,@rfId)";
        
            //bu işlemlerin gerçekleşmesi için scon bağlantısı açılır
            //ve kayıtlar eklendikten sonra bağlantı kapatılır
            scon.Open();
            int sonuc = kayitEkle.ExecuteNonQuery();
            scon.Close();

            //kayıt eklendi ise ilgili mesajı göster ve textboxları temizle
            if(sonuc != null) {
                MessageBox.Show("KAYIT EKLENDİ");
                textBox7.Clear();
                textBox6.Clear();
                textBox5.Clear();
                textBox4.Clear();
                textBox3.Clear();
                textBox2.Clear();
                textBox1.Clear();  
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //portun açık olup olmadığını kontrol et
            if(serialPort1.IsOpen) {
                //portu kapat ve kullanıcıya portun kullanımda olduğunu belirt
                serialPort1.Close();
                MessageBox.Show("com portu kullanılıyor");
            }
            else {
                serialPort1.Open();
            }
        }

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e) {
            string rfIdKart = serialPort1.ReadLine();
            textBox7.Text = rfIdKart;
            serialPort1.Close();
        }

        
    }
}
