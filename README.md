> "Saya Rama Taufik Azkia dengan NIM 2508497 mengerjakan Tugas Praktikum 1 dalam mata kuliah Desain dan Pemrograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin."

*— Janji*

# GARIS BESAR
CINEMA ABSOLUT merupakan aplikasi yang mengelola data film. Tersedia dalam 2 *interface*: CLI (C++, Java, Python) dan *web* (PHP). Setiap implementasi memiliki 7 atribut utama:
  1. ID, atribut angka unik yang dihitung otomatis oleh sistem. Pada implementasi CLI, ID diambil dari indeks *record* pada *array*, sehingga dapat berubah jika indeks sebelumnya dihapus, **namun** dipastikan tetap unik. Khusus implementasi *web*, ID tidak berubah dan dihitung dari ID terbesar sebelumnya + 1 (1 jika merupakan record pertama), karena adanya penyimpanan gambar;
  2. Judul (`title`), atribut wajib yang menyimpan data judul film;
  3. Direktor (`director`), atribut yang menyimpan data direktor film. Bernilai '-' jika kosong;
  4. Bahasa (`lang`), atribut yang menyimpan bahasa utama yang digunakan dalam film. Bernilai '-' jika kosong;
  5. Durasi (`minutes`), atribut yang menyimpan durasi film dalam menit. Bernilai 0 jika kosong;
  6. Tahun rilis (`year`), atribut yang menyimpan data perilisan perdana film. Bernilai 0 jika kosong;
  7. Harga tiker (`price`), atribut yang menyimpan data harga tiket. Bernilai 0 jika kosong.

**Khusus** untuk **implementasi web**, terdapat atribut tambahan 'Gambar promosi' (`img_url`). Hal ini yang menyebabkan 'ID' implementasi *web* dibuat tidak berubah, karena nama gambar disimpan sesuai ID-nya.

# FITUR
1. Tambah data baru;
2. Lihat data;
3. Ubah data berdasarkan ID;
4. Hapus data berdasarkan ID;
5. Penyimpanan data berbasis `session` di implementasi *web*;
6. Pencarian data berdasarkan 'Judul' dan 'Direktor' film.

# ERROR HANDLING
*Error handling* dibawah berlaku untuk semua implementasi. Saat terjadi *error*, program akan mengembalikan pesan dan meminta ulang *input* yang sesuai.
  1. Mencoba *input string* / karakter non-angka pada atribut angka:

  | CLI | WEB |
  | --- | --- |
  | ![Screenshot CLI](documentations/str_to_int-CLI.png) | ![Screenshot Web](documentations/str_to_int-Web.png) |
  2. Mencoba *input* angka negatif pada atribut angka (semua atribut angka harus positif atau 0):

  | CLI | WEB |
  | --- | --- |
  | ![Screenshot CLI](documentations/neg_to_int-CLI.png) | ![Screenshot Web](documentations/neg_to_int-Web.png) |
  3. Mencoba *input* angka desimal pada atribut angka (semua atribut angka harus bilangan bulat):

  | CLI | WEB |
  | --- | --- |
  | ![Screenshot CLI](documentations/dec_to_int-CLI.png) | ![Screenshot Web](documentations/dec_to_int-Web.png) |
  4. Mencoba mengosongkan atribut 'Judul':

  | CLI | WEB |
  | --- | --- |
  | ![Screenshot CLI](documentations/empty_title-CLI.png) | ![Screenshot Web](documentations/empty_title-Web.png) |

# DOKUMENTASI FITUR
1. Menambahkan data (+ *before* & *after*)

| CLI | WEB |
| --- | --- |
| ![Create in CLI](documentations/create-CLI.png) | ![Create in Web](documentations/create-Web.png) |
| ![Before create in CLI](documentations/create_before-CLI.png) | ![Before create in Web](documentations/create_before-Web.png) |
| ![After create in CLI](documentations/create_after-CLI.png) | ![After create in Web](documentations/create_after-Web.png) |
2. Melihat data

| CLI | WEB |
| --- | --- |
| ![Read in CLI](documentations/read-CLI.png) | ![Read in Web](documentations/read-Web.png) |
2. Mencari data. Pencarian dibuat berdasarkan judul atau nama direktor, dan bersifat *case-insensitive*

| CLI | WEB |
| --- | --- |
| ![Search in CLI](documentations/search-CLI.png) | ![Search in Web](documentations/search-Web.png) |
4. Merubah data (+ *before* & *after*)

| CLI | WEB |
| --- | --- |
| ![Update in CLI](documentations/update-CLI.png) | ![Update in Web](documentations/update-Web.png) |
| ![Before update in CLI](documentations/update_before-CLI.png) | ![Before update in Web](documentations/update_before-Web.png) |
| ![After update in CLI](documentations/update_after-CLI.png) | ![After update in Web](documentations/update_after-Web.png) |
5. Menghapus data (+ *before* & *after*)

| CLI | WEB |
| --- | --- |
| ![Delete in CLI](documentations/delete-CLI.png) | ![Delete in Web](documentations/delete-Web.png) |
| ![Before delete in CLI](documentations/delete_before-CLI.png) | ![Before delete in Web](documentations/delete_before-Web.png) |
| ![After delete in CLI](documentations/delete_after-CLI.png) | ![After delete in Web](documentations/delete_after-Web.png) |

# CATATAN
Untuk Implementasi Web, pastikan membuka laman Main.php terlebih dahulu, karena data dummy diisi ketika masuk ke laman Main.php dalam keadaan belum ada data session. Pada laman Create.php dan Update.php, terdapat inisiasi session kosong untuk jaga-jaga, sehingga data dummy dari laman Main.php tidak akan masuk jika membuka laman Create.php atau Update.php terlebih dahulu. 

Jika sudah terlanjur membuka laman Create.php atau Update.php, maka hapus session dengan melakukan klik kanan, lalu Inspect -> Application -> Cookies, dan hapus session-nya.

<img src="documentations/_watermark.png" width="250px" align="right">