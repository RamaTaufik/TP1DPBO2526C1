from Movie import Movie

# Panjang maksimum dari setiap atribut milik semua objek. Secara default, maksimum nya di-set terlebih dahulu pada
# panjang judul masing-masing kolom (ID | Judul | Direktor | Bahasa | Durasi | Tahun | Harga)
max_lens = [2, 5, 8, 6, 6, 5, 5]

def intlen(num):
  if num < 10:
    return 1
  return intlen(num // 10) + 1

def printchar(n, c):
  print(c * n, end="")

def printborder():
  for i in range(7):
    print("+", end="")
    printchar(max_lens[i] + 2, "-")
  print("+")

def printMovies(ms):
  printborder()
  print("| ID", end="")
  printchar(max_lens[0] - 2, " ")
  print(" | Judul", end="")
  printchar(max_lens[1] - 5, " ")
  print(" | Direktor", end="")
  printchar(max_lens[2] - 8, " ")
  print(" | Bahasa", end="")
  printchar(max_lens[3] - 6, " ")
  print(" | Durasi", end="")
  printchar(max_lens[4] - 6, " ")
  print(" | Tahun", end="")
  printchar(max_lens[5] - 5, " ")
  print(" | Harga", end="")
  printchar(max_lens[6] - 5, " ")
  print(" |")
  printborder()

  for i in range(len(ms)):
    print("| ", end="")
    printchar(max_lens[0] - intlen(i + 1), " ")
    print(f"{i + 1} | {ms[i].getTitle()}", end="")
    printchar(max_lens[1] - len(ms[i].getTitle()), " ")

    print(f" | {ms[i].getDirector()}", end="")
    printchar(max_lens[2] - len(ms[i].getDirector()), " ")

    print(f" | {ms[i].getLang()}", end="")
    printchar(max_lens[3] - len(ms[i].getLang()), " ")

    print(" | ", end="")
    printchar(max_lens[4] - 1 - intlen(ms[i].getMinutes()), " ")
    print(f"{ms[i].getMinutes()}m", end="")

    print(f" | {ms[i].getYear()}", end="")
    printchar(max_lens[5] - intlen(ms[i].getYear()), " ")

    print(" | Rp", end="")
    printchar(max_lens[6] - 2 - intlen(ms[i].getPrice()), " ")
    print(f"{ms[i].getPrice()} |")

    printborder()


def main():
  movies = []
  choice = "0"

  movies.append(Movie("Interstellar", "Christopher Nolan", "Inggris", 169, 2014, 30000))
  movies.append(Movie("Inception", "Christopher Nolan", "Inggris", 148, 2010, 35000))
  movies.append(Movie("Parasite", "Bong Joon-ho", "Korea", 132, 2019, 40000))
  movies.append(Movie("Laskar Pelangi", "Riri Riza", "Indonesia", 125, 2008, 25000))
  movies.append(Movie("Spirited Away", "Hayao Miyazaki", "Jepang", 125, 2001, 30000))
  movies.append(Movie("The Dark Knight", "Christopher Nolan", "Inggris", 152, 2008, 35000))
  movies.append(Movie("Pengabdi Setan", "Joko Anwar", "Indonesia", 107, 2017, 30000))
  movies.append(Movie("Godzilla Minus One", "Takashi Yamazaki", "Jepang", 125, 2023, 40000))

  max_lens[1] = 18
  max_lens[2] = 17
  max_lens[3] = 9
  max_lens[4] = 6
  max_lens[5] = 5
  max_lens[6] = 7

  print("    ____  __  __   __  ____  __   __  ______    ______  _____   _____  ______  __    __  __  _____")
  print("   / __/ / / /  | / / / __/ /  |_/ / / / / /   / / / / / // /  /  __/ / __  / / /   / / / / /_  _/")
  print("  / /_  / / / /||/ / / __/ / /|_/ / / /_/ /   / /_/ / / /_/ / /__  / / /_/ / / /_  / /_/ /   / /")
  print(" /___/ /_/ /_/ |__/ /___/ /_/  /_/ /_/ /_/   /_/ /_/ /_____/ /____/ /_____/ /___/ /_____/   /_/")
  print("\n> CINEMA ABSOLUT DATA CENTER <")

  while True:
    if choice in ["0", "1", "2", "3", "4", "5"]:
      print("\n1. Lihat data film")
      print("2. Tambah data film baru")
      print("3. Ubah data film")
      print("4. Hapus data film")
      print("5. Cari film")
      print("0. Keluar")

    choice = input("\nPilih opsi: ")

    if choice == "1":
      printMovies(movies)
    elif choice == "2":
      res = 0
      temp_movie = Movie("-", "-", "-", 0, 0, 0)

      while True:
        temp_str = input("Masukkan judul film     : ")
        res = temp_movie.setTitle(temp_str)
        if res == 0:
          if max_lens[1] < len(temp_movie.getTitle()):
            max_lens[1] = len(temp_movie.getTitle())
          break

      temp_str = input("Masukkan nama direktor  : ")
      temp_movie.setDirector(temp_str)
      if max_lens[2] < len(temp_movie.getDirector()):
        max_lens[2] = len(temp_movie.getDirector())

      temp_str = input("Masukkan bahasa dub     : ")
      temp_movie.setLang(temp_str)
      if max_lens[3] < len(temp_movie.getLang()):
        max_lens[3] = len(temp_movie.getLang())

      while True:
        try:
          temp_int = int(input("Masukkan durasi (menit) : "))
          res = temp_movie.setMinutes(temp_int)
        except ValueError:
          print("Durasi harus bilangan bulat positif!")
          res = -1

        if res == 0:
          if max_lens[4] < intlen(temp_movie.getMinutes()) + 1:
            max_lens[4] = intlen(temp_movie.getMinutes()) + 1
          break

      while True:
        try:
          temp_int = int(input("Masukkan tahun rilis    : "))
          res = temp_movie.setYear(temp_int)
        except ValueError:
          print("Tahun rilis harus bilangan bulat positif!")
          res = -1

        if res == 0:
          if max_lens[5] < intlen(temp_movie.getYear()):
            max_lens[5] = intlen(temp_movie.getYear())
          break

      while True:
        try:
          temp_int = int(input("Masukkan harga          : Rp"))
          res = temp_movie.setPrice(temp_int)
        except ValueError:
          print("Harga harus bilangan bulat positif!")
          res = -1

        if res == 0:
          if max_lens[6] < intlen(temp_movie.getPrice()) + 2:
            max_lens[6] = intlen(temp_movie.getPrice()) + 2
          break

      movies.append(temp_movie)
      if max_lens[0] < intlen(len(movies)):
        max_lens[0] = intlen(len(movies))
    elif choice == "3":
      if len(movies) <= 0:
        print("Tidak ada data film untuk diubah!", end="")
        choice = "-1"
      else:
        temp_id = 0

        while True:
          try:
            temp_id = int(input("Masukkan ID film : "))
            if temp_id < 0 or temp_id > len(movies):
              print(f"Tidak ada ID {temp_id}! (masukkan 0 untuk membatalkan)")
            else:
              break
          except ValueError:
            print("ID merupakan bilangan bulat positif! (masukkan 0 untuk membatalkan)")
            temp_id = -1

        if temp_id != 0:
          temp_choice = "0"
          while True:
            res = 0

            if temp_choice in ["0", "1", "2", "3", "4", "5", "6"]:
              print(f"\n1. Judul    : {movies[temp_id - 1].getTitle()}")
              print(f"2. Direktor : {movies[temp_id - 1].getDirector()}")
              print(f"3. Bahasa   : {movies[temp_id - 1].getLang()}")
              print(f"4. Durasi   : {movies[temp_id - 1].getMinutes()}m")
              print(f"5. Tahun    : {movies[temp_id - 1].getYear()}")
              print(f"6. Harga    : Rp{movies[temp_id - 1].getPrice()}")
              print("0. Kembali")

            temp_choice = input("\nMasukkan nomor atribut untuk diubah : ")

            if temp_choice == "1":
              while True:
                temp_str = input("Masukkan judul baru : ")
                res = movies[temp_id - 1].setTitle(temp_str)
                if res == 0:
                  if max_lens[1] < len(movies[temp_id - 1].getTitle()):
                    max_lens[1] = len(movies[temp_id - 1].getTitle())
                  break
            elif temp_choice == "2":
              temp_str = input("Masukkan nama direktor baru : ")
              movies[temp_id - 1].setDirector(temp_str)
              if max_lens[2] < len(movies[temp_id - 1].getDirector()):
                max_lens[2] = len(movies[temp_id - 1].getDirector())
            elif temp_choice == "3":
              temp_str = input("Masukkan bahasa dub baru : ")
              movies[temp_id - 1].setLang(temp_str)
              if max_lens[3] < len(movies[temp_id - 1].getLang()):
                max_lens[3] = len(movies[temp_id - 1].getLang())
            elif temp_choice == "4":
              while True:
                try:
                  temp_int = int(input("Masukkan durasi baru : "))
                  res = movies[temp_id - 1].setMinutes(temp_int)
                except ValueError:
                  print("Durasi harus bilangan bulat positif!")
                  res = -1

                if res == 0:
                  if max_lens[4] < intlen(movies[temp_id - 1].getMinutes()) + 1:
                    max_lens[4] = intlen(movies[temp_id - 1].getMinutes()) + 1
                  break
            elif temp_choice == "5":
              while True:
                try:
                  temp_int = int(input("Masukkan tahun rilis baru : "))
                  res = movies[temp_id - 1].setYear(temp_int)
                except ValueError:
                  print("Tahun rilis harus bilangan bulat positif!")
                  res = -1

                if res == 0:
                  if max_lens[5] < intlen(movies[temp_id - 1].getYear()):
                    max_lens[5] = intlen(movies[temp_id - 1].getYear())
                  break
            elif temp_choice == "6":
              while True:
                try:
                  temp_int = int(input("Masukkan harga baru : Rp"))
                  res = movies[temp_id - 1].setPrice(temp_int)
                except ValueError:
                  print("Harga harus bilangan bulat positif!")
                  res = -1

                if res == 0:
                  if max_lens[6] < intlen(movies[temp_id - 1].getPrice()) + 2:
                    max_lens[6] = intlen(movies[temp_id - 1].getPrice()) + 2
                  break
            elif temp_choice != "0":
              print(f"Tidak ada opsi atribut '{temp_choice}'!", end="")

            if temp_choice == "0":
              break
    elif choice == "4":
      if len(movies) <= 0:
        print("Tidak ada data film untuk dihapus!", end="")
        choice = "-1"
      else:
        temp_id = 0
        while True:
          try:
            temp_id = int(input("Masukkan ID film : "))
            if temp_id < 0 or temp_id > len(movies):
              print(f"Tidak ada ID {temp_id}! (masukkan 0 untuk membatalkan)")
            else:
              break
          except ValueError:
            print("ID merupakan bilangan bulat positif! (masukkan 0 untuk membatalkan)")
            temp_id = -1

        if temp_id != 0:
          print(f'Berhasil menghapus film "{movies[temp_id - 1].getTitle()}"!')
          movies.pop(temp_id - 1)
    elif choice == "5":
      temp_movies = []
      temp_str = input("Masukkan kata kunci pencarian : ")
      temp_str = temp_str.lower()

      for movie in movies:
        if(
          temp_str in movie.getTitle().lower()
          or temp_str in movie.getDirector().lower()
        ):
          temp_movies.append(movie)

      printMovies(temp_movies)
    elif choice != "0":
      print(f"Tidak ada opsi '{choice}'!", end="")

    if choice == "0":
      break

if __name__ == "__main__":
  main()