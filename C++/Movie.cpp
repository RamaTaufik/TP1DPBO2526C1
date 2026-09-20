#include <string>
#include <vector>
#include <iostream>

class Movie {
  private:
    std::string title, director, lang;
    int minutes, year, price;

  public:
    Movie() {}

    Movie(std::string t, std::string d, std::string l, int m, int y, int p) {
      setTitle(t);
      setDirector(d);
      setLang(l);
      setMinutes(m);
      setYear(y);
      setPrice(p);
    }

    int setTitle(std::string t) {
      if(t == "") {
        std::cout << "Judul tidak bisa kosong!\n";
        return -1;
      }

      title = t;
      return 0;
    }
    std::string getTitle() {
      return title;
    }

    void setDirector(std::string d) {
      if(d == "") {
        director = "-";
      } else {
        director = d;
      }
    }
    std::string getDirector() {
      return director;
    }

    void setLang(std::string l) {
      if(l == "") {
        lang = "-";
      } else {
        lang = l;
      }
    }
    std::string getLang() {
      return lang;
    }

    int setMinutes(int m) {
      if(m < 0) {
        std::cout << "Durasi harus bilangan bulat positif!\n";
        return -1;
      }

      minutes = m;
      return 0;
    }
    int getMinutes() {
      return minutes;
    }

    int setYear(int y) {
      if(y < 0) {
        std::cout << "Tahun rilis harus bilangan bulat positif!\n";
        return -1;
      }

      year = y;
      return 0;
    }
    int getYear() {
      return year;
    }

    int setPrice(int p) {
      if(p < 0) {
        std::cout << "Harga harus bilangan bulat positif!\n";
        return -1;
      }

      price = p;
      return 0;
    }
    int getPrice() {
      return price;
    }

    ~Movie() {}
};