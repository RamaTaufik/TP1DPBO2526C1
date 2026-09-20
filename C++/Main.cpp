#include "Movie.cpp"
#include <cmath>

// Panjang maksimum dari setiap atribut milik semua objek. Secara default, maksimum nya di-set terlebih dahulu pada
// panjang nama masing-masing atribut (ID | Judul | Direktor | Bahasa | Durasi | Tahun | Harga)
int max_lens[] = {2, 5, 8, 6, 6, 5, 5};

// Fungsi untuk menghitung jumlah digit suatu integer positif
int intlen(int num) {
  if(num < 10) {
    return 1;
  }
  return intlen(num / 10) + 1;
}

// Fungsi untuk merubah string menjadi integer
int cstrtoint(std::string str) {
  int num = 0;

  for(int i = 0; i < str.size(); i++) {
    if(str[i] < '0' || str[i] > '9') {
      // Karena semua atribut integer dipastikan hanya bilangan bulat positif, maka hanya digit berupa angka 0 sampai 9
      // yang akan diterima, sehingga fungsi ini juga sekaligus menjadi filter input
      return -1;
    } else {
      num = (num * 10) + (str[i] - '0');
    }
  }

  return num;
}

// Fungsi yang merubah keseluruhan string menjadi lowercase
std::string strToLower(std::string str) {
  int i = 0;
  std::string new_str = str;

  while(i < str.size()) {
    // Memastikan bahwa hanya karakter abjad romawi saja yang diubah ke lowercase
    if(new_str[i] >= 'A' && new_str[i] <= 'Z') new_str[i] += 32;

    i++;
  }

  return new_str;
}

// Prosedur untuk meng-print karakter c sebanyak n
void printchar(int n, char c) {
  for(int i = 0; i < n; i++) {
    std::cout << c;
  }
}

// Prosedur untuk meng-print border pada tabel di CLI
void printborder() {
  for(int i = 0; i < 7; i++) {
    std::cout << "+";
    printchar(max_lens[i] + 2, '-');
  }
  std::cout << "+\n";
}

// Prosedur untuk meng-print data film ke bentuk tabel
void printMovies(std::vector<Movie> ms) {
  // Print header tabel
  printborder();
  std::cout << "| ID";
  printchar(max_lens[0] - 2, ' ');
  std::cout << " | Judul";
  printchar(max_lens[1] - 5, ' ');
  std::cout << " | Direktor";
  printchar(max_lens[2] - 8, ' ');
  std::cout << " | Bahasa";
  printchar(max_lens[3] - 6, ' ');
  std::cout << " | Durasi";
  printchar(max_lens[4] - 6, ' ');
  std::cout << " | Tahun";
  printchar(max_lens[5] - 5, ' ');
  std::cout << " | Harga";
  printchar(max_lens[6] - 5, ' ');
  std::cout << " |\n";
  printborder();

  for(int i = 0; i < ms.size(); i++) {
    // Print masing-masing data
    std::cout << "| ";
    printchar(max_lens[0] - intlen(i + 1), ' ');
    std::cout << (i + 1) << " | " << ms[i].getTitle();
    printchar(max_lens[1] - ms[i].getTitle().size(), ' ');

    std::cout << " | " << ms[i].getDirector();
    printchar(max_lens[2] - ms[i].getDirector().size(), ' ');
    
    std::cout << " | " << ms[i].getLang();
    printchar(max_lens[3] - ms[i].getLang().size(), ' ');

    std::cout << " | ";
    printchar(max_lens[4] - 1 - intlen(ms[i].getMinutes()), ' '); // Dikurangi satu karena ada penambahan 'm'
    std::cout << ms[i].getMinutes() << "m";

    std::cout << " | " << ms[i].getYear();
    printchar(max_lens[5] - intlen(ms[i].getYear()), ' ');

    std::cout << " | Rp";
    printchar(max_lens[6] - 2 - intlen(ms[i].getPrice()), ' '); // Dikurangi dua karena ada penambahan 'Rp'
    std::cout << ms[i].getPrice() << " |\n";

    printborder();
  }
}

int main() {
  std::vector<Movie> movies; // Vector data film
  std::string choice = "0"; // Variabel untuk input opsi

  // Data dummy
  movies.push_back(Movie("Interstellar", "Christopher Nolan", "Inggris", 169, 2014, 30000));
  movies.push_back(Movie("Inception", "Christopher Nolan", "Inggris", 148, 2010, 35000));
  movies.push_back(Movie("Parasite", "Bong Joon-ho", "Korea", 132, 2019, 40000));
  movies.push_back(Movie("Laskar Pelangi", "Riri Riza", "Indonesia", 125, 2008, 25000));
  movies.push_back(Movie("Spirited Away", "Hayao Miyazaki", "Jepang", 125, 2001, 30000));
  movies.push_back(Movie("The Dark Knight", "Christopher Nolan", "Inggris", 152, 2008, 35000));
  movies.push_back(Movie("Pengabdi Setan", "Joko Anwar", "Indonesia", 107, 2017, 30000));
  movies.push_back(Movie("Godzilla Minus One", "Takashi Yamazaki", "Jepang", 125, 2023, 40000));

  // Perubahan panjang maksimum setiap atribut setelah penambahan data dummy
  max_lens[1] = 18;
  max_lens[2] = 17;
  max_lens[3] = 9;
  max_lens[4] = 6;
  max_lens[5] = 5;
  max_lens[6] = 7;

  std::cout << "   ____  __  __   __  ____  __   __  ______    ______  _____   _____  ______  __    __  __  _____\n";
  std::cout << "  / __/ / / /  | / / / __/ /  |_/ / / / / /   / / / / / // /  /  __/ / __  / / /   / / / / /_  _/\n";
  std::cout << " / /_  / / / /||/ / / __/ / /|_/ / / /_/ /   / /_/ / / /_/ / /__  / / /_/ / / /_  / /_/ /   / /\n";
  std::cout << "/___/ /_/ /_/ |__/ /___/ /_/  /_/ /_/ /_/   /_/ /_/ /_____/ /____/ /_____/ /___/ /_____/   /_/\n";
  std::cout << "\n> CINEMA ABSOLUT DATA CENTER <";
  
  // Loop utama
  do{
    // Jika terjadi kesalahan dalam input opsi, tidak perlu print ulang pilihan opsi agar tidak memenuhi layar
    if(choice == "0" || choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5") {
      std::cout << "\n1. Lihat data film\n";
      std::cout << "2. Tambah data film baru\n";
      std::cout << "3. Ubah data film\n";
      std::cout << "4. Hapus data film\n";
      std::cout << "5. Cari film\n";
      std::cout << "0. Keluar\n";
    }
    std::cout << "\nPilih opsi: ";

    std::cin >> choice;

    if(choice == "1") {
      // Lihat semua data
      printMovies(movies);
    } else if(choice == "2") {
      // Tambah data
      int temp_int, res = 0;
      std::string temp_str;
      Movie temp_movie;

      do{
        std::cout << "Masukkan judul film     : ";
        // Ketika melakukan std::cin sebelumnya, ada sisa '\n' yang tidak terbawa ketika pengguna menekan Enter.
        // Kode di bawah 'melahap' '\n' sisaan tersebut agar input tidak seolah-olah ter-'skip'. Validasi res == 0
        // memastikan kode dibawah hanya dijalankan sekali karena jika berulang-ulang, juga akan seolah-olah ter-'skip'
        if(res == 0) std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, temp_str);
        res = temp_movie.setTitle(temp_str);
        // Cek panjang maksimum atribut 'Judul'
        if(res == 0 && max_lens[1] < temp_movie.getTitle().size()) max_lens[1] = temp_movie.getTitle().size();
      } while(res != 0);

      std::cout << "Masukkan nama direktor  : ";
      // Pemakaian std::getline konsekutif tidak perlu 'melahap' '\n' lagi
      std::getline(std::cin, temp_str);
      temp_movie.setDirector(temp_str);
      // Cek panjang maksimum atribut 'Direktor'
      if(max_lens[2] < temp_movie.getDirector().size()) max_lens[2] = temp_movie.getDirector().size();

      std::cout << "Masukkan bahasa dub     : ";
      std::getline(std::cin, temp_str);
      temp_movie.setLang(temp_str);
      // Cek panjang maksimum atribut 'Bahasa'
      if(max_lens[3] < temp_movie.getLang().size()) max_lens[3] = temp_movie.getLang().size();

      do{
        std::cout << "Masukkan durasi (menit) : ";
        // Input untuk atribut integer tetap menggunakan input string, dikarenakan ketika pengguna memasukkan string
        // saat input integer, C++ akan mengeluarkan error yang tidak bisa ditangkap dengan try-catch
        std::getline(std::cin, temp_str);
        // Daripada membuat fungsi baru sehingga dapat 'menangkap' error ketika memasukkan string pada input integer,
        // lebih simpel menerima input dalam string lalu di validasi manual
        temp_int = cstrtoint(temp_str);
        res = temp_movie.setMinutes(temp_int);
        // Cek panjang maksimum atribut 'Durasi'
        if(res == 0 && max_lens[4] < intlen(temp_movie.getMinutes()) + 1) max_lens[4] = intlen(temp_movie.getMinutes()) + 1;
      } while(res != 0);

      do{
        std::cout << "Masukkan tahun rilis    : ";
        std::getline(std::cin, temp_str);
        temp_int = cstrtoint(temp_str);
        res = temp_movie.setYear(temp_int);
        // Cek panjang maksimum atribut 'Tahun rilis'
        if(res == 0 && max_lens[5] < intlen(temp_movie.getYear())) max_lens[5] = intlen(temp_movie.getYear());
      } while(res != 0);

      do{
        std::cout << "Masukkan harga          : Rp";
        std::getline(std::cin, temp_str);
        temp_int = cstrtoint(temp_str);
        res = temp_movie.setPrice(temp_int);
        // Cek panjang maksimum atribut 'Harga tiket'
        if(res == 0 && max_lens[6] < intlen(temp_movie.getPrice()) + 2) max_lens[6] = intlen(temp_movie.getPrice()) + 2;
      } while(res != 0);

      movies.push_back(temp_movie);
      // Cek panjang maksimum atribut 'ID'. Atribut 'ID" disini menggunakan indeks vektor + 1, sehingga panjang digit
      // -nya dapat mudah dihitung dari jumlah item-nya
      if(max_lens[0] < intlen(movies.size())) max_lens[0] = intlen(movies.size());
    } else if(choice == "3") {
      // Ubah data
      if(movies.size() <= 0) {
        std::cout << "Tidak ada data film untuk diubah!";
        choice = "-1";
      } else {
        int temp_id = 0;

        // Blok kode do-while() disini memastikan ID yang dimasukkan benar-benar ada
        do{
          std::cout << "Masukkan ID film : ";
          if(std::cin >> temp_id) {
            if(temp_id < 0 || temp_id > movies.size()) std::cout << "Tidak ada ID " << temp_id << "! (masukkan 0 untuk membatalkan)\n";
          } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "ID merupakan bilangan bulat positif! (masukkan 0 untuk membatalkan)\n";
            temp_id = -1;
          }
        } while(temp_id < 0 || temp_id > movies.size());

        if(temp_id != 0) {
          std::string temp_choice = "0";

          do{
            int res = 0, temp_int;
            std::string temp_str;

            if(temp_choice == "0" || temp_choice == "1" || temp_choice == "2" || temp_choice == "3" || temp_choice == "4" || temp_choice == "5" || temp_choice == "6") {
              std::cout << "\n1. Judul    : " << movies[temp_id - 1].getTitle();
              std::cout << "\n2. Direktor : " << movies[temp_id - 1].getDirector();
              std::cout << "\n3. Bahasa   : " << movies[temp_id - 1].getLang();
              std::cout << "\n4. Durasi   : " << movies[temp_id - 1].getMinutes() << "m";
              std::cout << "\n5. Tahun    : " << movies[temp_id - 1].getYear();
              std::cout << "\n6. Harga    : Rp" << movies[temp_id - 1].getPrice();
              std::cout << "\n0. Kembali" << "\n";
            }

            std::cout << "\nMasukkan nomor atribut untuk diubah : ";
            std::cin >> temp_choice;

            if(temp_choice == "1") {
              do{
                std::cout << "Masukkan judul baru : ";
                if(res == 0) std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, temp_str);
                res = movies[temp_id - 1].setTitle(temp_str);
                if(res == 0 && max_lens[1] < movies[temp_id - 1].getTitle().size()) max_lens[1] = movies[temp_id - 1].getTitle().size();
              } while(res != 0);
            } else if(temp_choice == "2") {
              std::cout << "Masukkan nama direktor baru : ";
              // Karena input perubahan setiap atribut terpisah, dan diantara input atribut terdapat input untuk opsi, 
              // maka '\n' dari input opsi harus dilahap pada tiap input perubahan atribut
              if(res == 0) std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              std::getline(std::cin, temp_str);
              movies[temp_id - 1].setDirector(temp_str);
              if(max_lens[2] < movies[temp_id - 1].getDirector().size()) max_lens[2] = movies[temp_id - 1].getDirector().size();
            } else if(temp_choice == "3") {
              std::cout << "Masukkan bahasa dub baru : ";
              if(res == 0) std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              std::getline(std::cin, temp_str);
              movies[temp_id - 1].setLang(temp_str);
              if(max_lens[3] < movies[temp_id - 1].getLang().size()) max_lens[3] = movies[temp_id - 1].getLang().size();
            } else if(temp_choice == "4") {
              do{
                std::cout << "Masukkan durasi baru : ";
                if(res == 0) std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, temp_str);
                temp_int = cstrtoint(temp_str);
                res = movies[temp_id - 1].setMinutes(temp_int);
                if(res == 0 && max_lens[4] < intlen(movies[temp_id - 1].getMinutes()) + 1) max_lens[4] = intlen(movies[temp_id - 1].getMinutes()) + 1;
              } while(res != 0);
            } else if(temp_choice == "5") {
              do{
                std::cout << "Masukkan tahun rilis baru : ";
                if(res == 0) std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, temp_str);
                temp_int = cstrtoint(temp_str);
                res = movies[temp_id - 1].setYear(temp_int);
                if(res == 0 && max_lens[5] < intlen(movies[temp_id - 1].getYear())) max_lens[5] = intlen(movies[temp_id - 1].getYear());
              } while(res != 0);
            } else if(temp_choice == "6") {
              do{
                std::cout << "Masukkan harga baru : Rp";
                if(res == 0) std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, temp_str);
                temp_int = cstrtoint(temp_str);
                res = movies[temp_id - 1].setPrice(temp_int);
                if(res == 0 && max_lens[6] < intlen(movies[temp_id - 1].getPrice()) + 2) max_lens[6] = intlen(movies[temp_id - 1].getPrice()) + 2;
              } while(res != 0);
            } else if(temp_choice != "0") {
              std::cout << "Tidak ada opsi atribut '" << temp_choice << "'!";
            }
          } while(temp_choice != "0");
        }
      }
    } else if(choice == "4") {
      // Hapus data film
      if(movies.size() <= 0) {
        std::cout << "Tidak ada data film untuk dihapus!";
        choice = "-1";
      } else {
        int temp_id = 0;

        // Sama seperti di blok kode perubahan data, ada blok kode do-while() di awal untuk memastikan ID yang
        // dimasukkan benar-benar ada
        do{
          std::cout << "Masukkan ID film : ";
          if(std::cin >> temp_id) {
            if(temp_id < 0 || temp_id > movies.size()) std::cout << "Tidak ada ID " << temp_id << "! (masukkan 0 untuk membatalkan)\n";
          } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "ID merupakan bilangan bulat positif! (masukkan 0 untuk membatalkan)\n";
            temp_id = -1;
          }
        } while(temp_id < 0 || temp_id > movies.size());

        if(temp_id != 0) {
          std::cout << "Berhasil menghapus film \"" << movies[temp_id - 1].getTitle() << "\"!\n";
          movies.erase(movies.begin() + (temp_id - 1));
        }
      }
    } else if(choice == "5") {
      // Cari data spesifik. Pencarian dibuat berdasarkan atribut judul atau nama direktor
      std::vector<Movie> temp_movies;
      std::string temp_str = "";
      
      std::cout << "Masukkan kata kunci pencarian : ";
      // Seperti biasa, lahap dulu '\n' dari input opsi sebelumnya
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::getline(std::cin, temp_str);
      temp_str = strToLower(temp_str);

      // Filter vektor, pastikan hanya film yang mengandung kata kunci pada judul atau nama direktornya yang 
      // ditampilkan. Judul serta nama direktor dan kata kunci diubah ke lowercase sehingga pencarian menjadi
      // case-insensitive
      for(int i = 0; i < movies.size(); i++) {
        if(
          strToLower(movies[i].getTitle()).find(temp_str) != std::string::npos || 
          strToLower(movies[i].getDirector()).find(temp_str) != std::string::npos
        ) {
          temp_movies.push_back(movies[i]);
        }
      }

      printMovies(temp_movies);
    } else if(choice != "0") {
      std::cout << "Tidak ada opsi '" << choice << "'!";
    }
  } while(choice != "0");

  return 0;
}