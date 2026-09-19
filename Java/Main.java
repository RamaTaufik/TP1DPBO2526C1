import java.util.ArrayList;
import java.util.Scanner;

public class Main {
  private static int[] maxLens = {2, 5, 8, 6, 6, 5, 5};

  private static int intlen(int num) {
    if(num < 10) {
      return 1;
    }
    return intlen(num / 10) + 1;
  }

  private static void printchar(int n, char c) {
    for(int i = 0; i < n; i++) {
      System.out.print(c);
    }
  }

  private static void printborder() {
    for(int i = 0; i < 7; i++) {
      System.out.print("+");
      printchar(maxLens[i] + 2, '-');
    }
    System.out.println("+");
  }

  private static void printMovies(ArrayList<Movie> ms) {
    printborder();
    System.out.print("| ID");
    printchar(maxLens[0] - 2, ' ');
    System.out.print(" | Judul");
    printchar(maxLens[1] - 5, ' ');
    System.out.print(" | Direktor");
    printchar(maxLens[2] - 8, ' ');
    System.out.print(" | Bahasa");
    printchar(maxLens[3] - 6, ' ');
    System.out.print(" | Durasi");
    printchar(maxLens[4] - 6, ' ');
    System.out.print(" | Tahun");
    printchar(maxLens[5] - 5, ' ');
    System.out.print(" | Harga");
    printchar(maxLens[6] - 5, ' ');
    System.out.println(" |");
    printborder();

    for(int i = 0; i < ms.size(); i++) {
      System.out.print("| ");
      printchar(maxLens[0] - intlen(i + 1), ' ');
      System.out.print((i + 1) + " | " + ms.get(i).getTitle());
      printchar(maxLens[1] - ms.get(i).getTitle().length(), ' ');

      System.out.print(" | " + ms.get(i).getDirector());
      printchar(maxLens[2] - ms.get(i).getDirector().length(), ' ');

      System.out.print(" | " + ms.get(i).getLang());
      printchar(maxLens[3] - ms.get(i).getLang().length(), ' ');

      System.out.print(" | ");
      printchar(maxLens[4] - 1 - intlen(ms.get(i).getMinutes()), ' ');
      System.out.print(ms.get(i).getMinutes() + "m");

      System.out.print(" | " + ms.get(i).getYear());
      printchar(maxLens[5] - intlen(ms.get(i).getYear()), ' ');

      System.out.print(" | Rp");
      printchar(maxLens[6] - 2 - intlen(ms.get(i).getPrice()), ' ');
      System.out.println(ms.get(i).getPrice() + " |");

      printborder();
    }
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    ArrayList<Movie> movies = new ArrayList<>();
    String choice = "0";

    movies.add(new Movie("Interstellar", "Christopher Nolan", "Inggris", 169, 2014, 30000));
    movies.add(new Movie("Inception", "Christopher Nolan", "Inggris", 148, 2010, 35000));
    movies.add(new Movie("Parasite", "Bong Joon-ho", "Korea", 132, 2019, 40000));
    movies.add(new Movie("Laskar Pelangi", "Riri Riza", "Indonesia", 125, 2008, 25000));
    movies.add(new Movie("Spirited Away", "Hayao Miyazaki", "Jepang", 125, 2001, 30000));
    movies.add(new Movie("The Dark Knight", "Christopher Nolan", "Inggris", 152, 2008, 35000));
    movies.add(new Movie("Pengabdi Setan", "Joko Anwar", "Indonesia", 107, 2017, 30000));
    movies.add(new Movie("Godzilla Minus One", "Takashi Yamazaki", "Jepang", 125, 2023, 40000));

    maxLens[1] = 18;
    maxLens[2] = 17;
    maxLens[3] = 9;
    maxLens[4] = 6;
    maxLens[5] = 5;
    maxLens[6] = 7;

    System.out.println("   ____  __  __   __  ____  __   __  ______    ______  _____   _____  ______  __    __  __  _____");
    System.out.println("  / __/ / / /  | / / / __/ /  |_/ / / / / /   / / / / / // /  /  __/ / __  / / /   / / / / /_  _/");
    System.out.println(" / /_  / / / /||/ / / __/ / /|_/ / / /_/ /   / /_/ / / /_/ / /__  / / /_/ / / /_  / /_/ /   / /");
    System.out.println("/___/ /_/ /_/ |__/ /___/ /_/  /_/ /_/ /_/   /_/ /_/ /_____/ /____/ /_____/ /___/ /_____/   /_/");
    System.out.println("\n> CINEMA ABSOLUT DATA CENTER <");

    do{
      if(choice.equals("0") || choice.equals("1") || choice.equals("2") || choice.equals("3") || choice.equals("4") || choice.equals("5")) {
        System.out.println("\n1. Lihat data film");
        System.out.println("2. Tambah data film baru");
        System.out.println("3. Ubah data film");
        System.out.println("4. Hapus data film");
        System.out.println("5. Cari film");
        System.out.println("0. Keluar");
      }
      System.out.print("\nPilih opsi: ");

      choice = scanner.nextLine();

      if(choice.equals("1")) {
        printMovies(movies);
      } else if(choice.equals("2")) {
        int tempInt, res = 0;
        String tempStr;
        Movie tempMovie = new Movie();

        do{
          System.out.print("Masukkan judul film     : ");
          tempStr = scanner.nextLine();
          res = tempMovie.setTitle(tempStr);
          if(res == 0 && maxLens[1] < tempMovie.getTitle().length()) maxLens[1] = tempMovie.getTitle().length();
        } while(res != 0);

        System.out.print("Masukkan nama direktor  : ");
        tempStr = scanner.nextLine();
        tempMovie.setDirector(tempStr);
        if(maxLens[2] < tempMovie.getDirector().length()) maxLens[2] = tempMovie.getDirector().length();

        System.out.print("Masukkan bahasa dub     : ");
        tempStr = scanner.nextLine();
        tempMovie.setLang(tempStr);
        if(maxLens[3] < tempMovie.getLang().length()) maxLens[3] = tempMovie.getLang().length();

        do{
          System.out.print("Masukkan durasi (menit) : ");
          try{
            tempInt = Integer.parseInt(scanner.nextLine());
          } catch(NumberFormatException e) {
            tempInt = -1;
          }
          res = tempMovie.setMinutes(tempInt);
          if(res == 0 && maxLens[4] < intlen(tempMovie.getMinutes()) + 1) maxLens[4] = intlen(tempMovie.getMinutes()) + 1;
        } while(res != 0);

        do{
          System.out.print("Masukkan tahun rilis    : ");
          try{
            tempInt = Integer.parseInt(scanner.nextLine());
          } catch(NumberFormatException e) {
            tempInt = -1;
          }
          res = tempMovie.setYear(tempInt);
          if(res == 0 && maxLens[5] < intlen(tempMovie.getYear())) maxLens[5] = intlen(tempMovie.getYear());
        } while(res != 0);

        do{
          System.out.print("Masukkan harga          : Rp");
          try{
            tempInt = Integer.parseInt(scanner.nextLine());
          } catch(NumberFormatException e) {
            tempInt = -1;
          }
          res = tempMovie.setPrice(tempInt);
          if(res == 0 && maxLens[6] < intlen(tempMovie.getPrice()) + 2) maxLens[6] = intlen(tempMovie.getPrice()) + 2;
        } while(res != 0);

        movies.add(tempMovie);
        if(maxLens[0] < intlen(movies.size())) maxLens[0] = intlen(movies.size());
      } else if(choice.equals("3")) {
        if(movies.isEmpty()) {
          System.out.print("Tidak ada data film untuk diubah!");
          choice = "-1";
        } else {
          int tempId = 0;

          do{
            System.out.print("Masukkan ID film : ");
            try{
              tempId = Integer.parseInt(scanner.nextLine());
              if(tempId < 0 || tempId > movies.size()) {
                System.out.println("Tidak ada ID " + tempId + "! (masukkan 0 untuk membatalkan)");
              }
            } catch(NumberFormatException e) {
              System.err.println("ID merupakan bilangan bulat positif! (masukkan 0 untuk membatalkan)");
              tempId = -1;
            }
          } while(tempId < 0 || tempId > movies.size());

          if(tempId != 0) {
            String tempChoice = "0";

            do{
              int res = 0, tempInt;
              String tempStr;

              if(tempChoice.equals("0") || tempChoice.equals("1") || tempChoice.equals("2") || tempChoice.equals("3") || tempChoice.equals("4") || tempChoice.equals("5") || tempChoice.equals("6")) {
                System.out.println("\n1. Judul    : " + movies.get(tempId - 1).getTitle());
                System.out.println("2. Direktor : " + movies.get(tempId - 1).getDirector());
                System.out.println("3. Bahasa   : " + movies.get(tempId - 1).getLang());
                System.out.println("4. Durasi   : " + movies.get(tempId - 1).getMinutes() + "m");
                System.out.println("5. Tahun    : " + movies.get(tempId - 1).getYear());
                System.out.println("6. Harga    : Rp" + movies.get(tempId - 1).getPrice());
                System.out.println("0. Kembali");
              }

              System.out.print("\nMasukkan nomor atribut untuk diubah : ");
              tempChoice = scanner.nextLine();

              if(tempChoice.equals("1")) {
                do{
                  System.out.print("Masukkan judul baru : ");
                  tempStr = scanner.nextLine();
                  res = movies.get(tempId - 1).setTitle(tempStr);
                  if(res == 0 && maxLens[1] < movies.get(tempId - 1).getTitle().length()) maxLens[1] = movies.get(tempId - 1).getTitle().length();
                } while(res != 0);
              } else if(tempChoice.equals("2")) {
                System.out.print("Masukkan nama direktor baru : ");
                tempStr = scanner.nextLine();
                movies.get(tempId - 1).setDirector(tempStr);
                if(maxLens[2] < movies.get(tempId - 1).getDirector().length()) maxLens[2] = movies.get(tempId - 1).getDirector().length();
              } else if(tempChoice.equals("3")) {
                System.out.print("Masukkan bahasa dub baru : ");
                tempStr = scanner.nextLine();
                movies.get(tempId - 1).setLang(tempStr);
                if(maxLens[3] < movies.get(tempId - 1).getLang().length()) maxLens[3] = movies.get(tempId - 1).getLang().length();
              } else if(tempChoice.equals("4")) {
                do{
                  System.out.print("Masukkan durasi baru : ");
                  try{
                    tempInt = Integer.parseInt(scanner.nextLine());
                  } catch(NumberFormatException e) {
                    tempInt = -1;
                  }
                  res = movies.get(tempId - 1).setMinutes(tempInt);
                  if(res == 0 && maxLens[4] < intlen(movies.get(tempId - 1).getMinutes()) + 1) maxLens[4] = intlen(movies.get(tempId - 1).getMinutes()) + 1;
                } while(res != 0);
              } else if(tempChoice.equals("5")) {
                do{
                  System.out.print("Masukkan tahun rilis baru : ");
                  try{
                    tempInt = Integer.parseInt(scanner.nextLine());
                  } catch(NumberFormatException e) {
                    tempInt = -1;
                  }
                  res = movies.get(tempId - 1).setYear(tempInt);
                  if(res == 0 && maxLens[5] < intlen(movies.get(tempId - 1).getYear())) maxLens[5] = intlen(movies.get(tempId - 1).getYear());
                } while(res != 0);
              } else if(tempChoice.equals("6")) {
                do{
                  System.out.print("Masukkan harga baru : Rp");
                  try{
                    tempInt = Integer.parseInt(scanner.nextLine());
                  } catch(NumberFormatException e) {
                    tempInt = -1;
                  }
                  res = movies.get(tempId - 1).setPrice(tempInt);
                  if(res == 0 && maxLens[6] < intlen(movies.get(tempId - 1).getPrice()) + 2) maxLens[6] = intlen(movies.get(tempId - 1).getPrice()) + 2;
                } while(res != 0);
              } else if(!tempChoice.equals("0")) {
                System.out.println("Tidak ada opsi atribut '" + tempChoice + "'!");
              }
            } while(!tempChoice.equals("0"));
          }
        }
      } else if(choice.equals("4")) {
        if(movies.isEmpty()) {
          System.out.print("Tidak ada data film untuk dihapus!");
          choice = "-1";
        } else {
          int tempId = 0;

          do{
            System.out.print("Masukkan ID film : ");
            try{
              tempId = Integer.parseInt(scanner.nextLine());
              if(tempId < 0 || tempId > movies.size()) {
                System.out.println("Tidak ada ID " + tempId + "! (masukkan 0 untuk membatalkan)");
              }
            } catch(NumberFormatException e) {
              System.err.println("ID merupakan bilangan bulat positif! (masukkan 0 untuk membatalkan)");
              tempId = -1;
            }
          } while(tempId < 0 || tempId > movies.size());

          if(tempId != 0) {
            System.out.println("Berhasil menghapus film \"" + movies.get(tempId - 1).getTitle() + "\"!");
            movies.remove(tempId - 1);
          }
        }
      } else if(choice.equals("5")) {
        ArrayList<Movie> tempMovies = new ArrayList<>();

        System.out.print("Masukkan kata kunci pencarian : ");
        String tempStr = scanner.nextLine().toLowerCase();

        for(Movie movie : movies) {
          if(
            movie.getTitle().toLowerCase().contains(tempStr) ||
            movie.getDirector().toLowerCase().contains(tempStr)
          ) {
            tempMovies.add(movie);
          }
        }

        printMovies(tempMovies);
      } else if(!choice.equals("0")) {
        System.out.print("Tidak ada opsi '" + choice + "'!");
      }
    } while(!choice.equals("0"));

    scanner.close();
  }
}