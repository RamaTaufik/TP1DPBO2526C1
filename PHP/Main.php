<?php
include "Movie.php";

session_start();

$search = "";

if(isset($_GET["search"])) $search = $_GET["search"];
if(!isset($_SESSION["movies"])) {
  $_SESSION["movies"] = [
    new Movie(1, "She-Hulk: Attorney at Law", "Kat Coiro", "Inggris", 306, 2022, 54000, "movie1.webp"),
    new Movie(2, "Avengers: Endgame", "Russo brothers", "Inggris", 181, 2019, 30000, "movie2.gif"),
    new Movie(3, "Moon Knight", "Mohamed Diab", "Inggris", 296, 2022, 65000, "movie3.jpg"),
    new Movie(4, "The Batman", "Matt Reeves", "Inggris", 176, 2022, 29000, "movie4.jpg"),
    new Movie(5, "Doctor Strang in the Multiverse of Madness", "Sam Raimi", "Inggris", 126, 2022, 43000, "movie5.jpg")
  ];
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>CINEMA ABSOLUT DATA CENTER</title>
  <link rel="stylesheet" href="style.css">
</head>
<body>
  <h1 class="title"><i>CINEMA ABSOLUT</i></h1>
  <main>
    <div class="table-container">
      <div class="input-container">
        <form method="GET">
          <input type="text" name="search" placeholder="Cari judul/direktor..." value="<?= $search ?>">
          <button type="submit">🔎︎</button>
        </form>
        <a href="Create.php">Tambah ＋</a>
      </div>
      <table>
        <thead>
          <tr>
            <th>ID</th>
            <th>Judul</th>
            <th>Direktor</th>
            <th>Bahasa Dub</th>
            <th>Durasi</th>
            <th>Tahun Rilis</th>
            <th>Harga Tiket</th>
            <th>Gambar Promosi</th>
            <th>Aksi</th>
          </tr>
        </thead>
        <tbody>
          <?php
          if(count($_SESSION["movies"]) > 0) {
            $movies = array_filter($_SESSION["movies"], fn($movie) => str_contains(strtolower($movie->getTitle()), strtolower($search)) || str_contains(strtolower($movie->getDirector()), strtolower($search)));

            foreach($movies as $movie) {
          ?>
            <tr>
              <td><?= $movie->getId() ?></td>
              <td><?= $movie->getTitle() ?></td>
              <td><?= $movie->getDirector() ?></td>
              <td><?= $movie->getLang() ?></td>
              <td><?= $movie->getMinutes()." menit" ?></td>
              <td><?= $movie->getYear() ?></td>
              <td><?= "Rp".$movie->getPrice() ?></td>
              <td>
                <?= $movie->getImgUrl() === "-"? "-": "<img src=\"images/".$movie->getImgUrl()."\">" ?>
              </td>
              <td>
                <form method="POST" action="Delete.php">
                  <input type="hidden" name="id" value="<?= $movie->getId() ?>">
                  <a href="Update.php?id=<?= $movie->getId() ?>" class="button button-warning">Edit</a>
                  <button type="submit" class="button button-danger" onclick="return confirm('Yakin hapus?')">Hapus</button>
                </form>
                <form method="POST" action="DeleteImg.php">
                  <input type="hidden" name="id" value="<?= $movie->getId() ?>">
                  <button type="submit" class="button button-danger" onclick="return confirm('Yakin hapus gambar?')">Hapus Gambar</button>
                </form>
              </td>
            </tr>
          <?php } } else { ?>
          <tr>
            <td colspan="9" class="table-no-data">
              <h3>Tidak ada data film</h3>
            </td>
          </tr>
          <?php } ?>
        </tbody>
      </table>
    </div>
  </main>
</body>
</html>