public class Movie {
  private String title, director, lang;
  private int minutes, year, price;

  public Movie() {}

  public Movie(String t, String d, String l, int m, int y, int p) {
    setTitle(t);
    setDirector(d);
    setLang(l);
    setMinutes(m);
    setYear(y);
    setPrice(p);
  }

  public int setTitle(String t) {
    if(t == null || t.isEmpty()) {
      System.out.println("Judul tidak bisa kosong!");
      return -1;
    }

    title = t;
    return 0;
  }
  public String getTitle() {
    return title;
  }

  public void setDirector(String d) {
    if(d == null || d.isEmpty()) {
      director = "-";
    } else {
      director = d;
    }
  }
  public String getDirector() {
    return director;
  }

  public void setLang(String l) {
    if(l == null || l.isEmpty()) {
      lang = "-";
    } else {
      lang = l;
    }
  }
  public String getLang() {
      return lang;
  }

  public int setMinutes(int m) {
    if(m < 0) {
      System.out.println("Durasi harus bilangan bulat positif!");
      return -1;
    }

    minutes = m;
    return 0;
  }
  public int getMinutes() {
    return minutes;
  }

  public int setYear(int y) {
    if(y < 0) {
      System.out.println("Tahun rilis harus bilangan bulat positif!");
      return -1;
    }

    year = y;
    return 0;
  }
  public int getYear() {
    return year;
  }

  public int setPrice(int p) {
    if(p < 0) {
      System.out.println("Harga harus bilangan bulat positif!");
      return -1;
    }

    price = p;
    return 0;
  }
  public int getPrice() {
    return price;
  }
}