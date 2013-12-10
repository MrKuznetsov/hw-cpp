using System;
using System.IO;
using System.Security.Cryptography;
using System.Net.Sockets;


namespace Task2
{
    class Program
    {
        public static void Main(string[] args)
        {
            try
            {
                TcpClient TCP = new TcpClient("91.151.187.54", 7200);
               // TcpClient TCP = new TcpClient("localhost", 7200);
                NetworkStream NetStream = TCP.GetStream();

                RijndaelManaged RMCrypto = new RijndaelManaged();

                byte[] Key = {(byte) 146, (byte) 27, (byte) 230, (byte) 69, (byte) 148, (byte) 87, (byte) 55, (byte) 144, (byte) 126,
                                 (byte) 30, (byte) 240, (byte) 203, (byte) 57, (byte) 240, (byte) 149, (byte) 26, (byte) 154,
                                 (byte) 187, (byte) 221, (byte) 96, (byte) 127, (byte) 139, (byte) 196, (byte) 1, (byte) 134, (byte) 65, (byte) 106,
                                 (byte) 60, (byte) 172, (byte) 242, (byte) 183, (byte) 252};
                byte[] IV = { (byte) 187, (byte) 185, (byte) 225, (byte) 0, (byte) 118, (byte) 29, (byte) 173, (byte) 225, (byte) 84,                                 
                                (byte) 138, (byte) 36, (byte) 252, (byte) 159, (byte) 182, (byte) 201, (byte) 114 };

                CryptoStream CryptStream = new CryptoStream(NetStream,
                RMCrypto.CreateEncryptor(Key, IV),
                CryptoStreamMode.Write);

                StreamWriter SWriter = new StreamWriter(CryptStream);

                SWriter.WriteLine("Kuznetsov Vyacheslav");

                Console.WriteLine("The message was sent.");

                SWriter.Close();
                CryptStream.Close();
                NetStream.Close();
                TCP.Close();
            }
            catch
            {
                Console.WriteLine("The connection failed.");
            }
            Console.ReadKey();
        }
    }

  
}
