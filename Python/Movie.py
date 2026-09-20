class Movie:
  def __init__(self, t, d, l, m, y, p):
    self.__title = str(t)    # Judul
    self.__director = str(d) # Direktor
    self.__lang = str(l)     # Bahasa
    self.__minutes = int(m)  # Durasi
    self.__year = int(y)     # Tahun rilis
    self.__price = int(p)    # Harga tiket

  def setTitle(self, t):
    if not t:
      print("Judul tidak bisa kosong!")
      return -1
    self.__title = t
    return 0
  def getTitle(self):
    return self.__title

  def setDirector(self, d):
    if not d:
      self.__director = "-"
    else:
      self.__director = d
  def getDirector(self):
    return self.__director

  def setLang(self, l):
    if not l:
      self.__lang = "-"
    else:
      self.__lang = l
  def getLang(self):
    return self.__lang

  def setMinutes(self, m):
    if m < 0:
      print("Durasi harus bilangan bulat positif!")
      return -1
    self.__minutes = m
    return 0
  def getMinutes(self):
    return self.__minutes

  def setYear(self, y):
    if y < 0:
      print("Tahun rilis harus bilangan bulat positif!")
      return -1
    self.__year = y
    return 0
  def getYear(self):
    return self.__year

  def setPrice(self, p):
    if p < 0:
      print("Harga harus bilangan bulat positif!")
      return -1
    self.__price = p
    return 0
  def getPrice(self):
    return self.__price