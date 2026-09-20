<?php
include "Movie.php";

session_start();

$e_msg = "";
$e_idx = 0;

if($_SERVER['REQUEST_METHOD'] === 'POST') {
  if(!isset($_SESSION["movies"])) {
    $_SESSION["movies"] = [
      new Movie(1, "She-Hulk: Attorney at Law", "Kat Coiro", "Inggris", 306, 2022, 54000, "movie1.webp"),
      new Movie(2, "Avengers: Endgame", "Russo brothers", "Inggris", 181, 2019, 30000, "movie2.gif"),
      new Movie(3, "Moon Knight", "Mohamed Diab", "Inggris", 296, 2022, 65000, "movie3.jpg"),
      new Movie(4, "The Batman", "Matt Reeves", "Inggris", 176, 2022, 29000, "movie4.jpg"),
      new Movie(5, "Doctor Strang in the Multiverse of Madness", "Sam Raimi", "Inggris", 126, 2022, 43000, "movie5.jpg")
    ];
  }

  $title = $_POST["title"];
  if($title === "") {
    $e_msg = "Judul tidak boleh kosong!";
    $e_idx = 1;
  } else {
    $director = $_POST["director"];
    $lang = $_POST["lang"];

    $minutes = $_POST["minutes"];
    if($minutes !== "" && !ctype_digit($minutes)) {
      $e_msg = "Durasi harus berupa bilangan bulat positif!";
      $e_idx = 4;
    } else {
      $minutes = $minutes === ""? 0: (int)$minutes;
    
      $year = $_POST["year"];
      if($year !== "" && !ctype_digit($year)) {
        $e_msg = "Tahun rilis harus berupa bilangan bulat positif!";
        $e_idx = 5;
      } else {
        $year = $year === ""? 0: (int)$year;

        $price = $_POST["price"];
        if($price !== "" && !ctype_digit($price)) {
          $e_msg = "Harga tiket harus berupa bilangan bulat positif!";
          $e_idx = 6;
        } else {
          $price = $price === ""? 0: (int)$price;
          $img_url = "-";
          $id = count($_SESSION["movies"]) > 0? (int)($_SESSION["movies"][array_key_last($_SESSION["movies"])]->getId()) + 1: 1;

          if(isset($_FILES['img'])) {
            $img = $_FILES['img'];
            $file_name = 'movie'.$id.'.'.strtolower(pathinfo($img['name'], PATHINFO_EXTENSION));
            $target_dir = __DIR__.'/images/';

            if (!is_dir($target_dir)) {
              mkdir($target_dir, 0755, true);
            }

            $target_path = $target_dir . $file_name;

            if(move_uploaded_file($img['tmp_name'], $target_path)) {
              $img_url = $file_name;
            }
          }
          

          $_SESSION["movies"][] = new Movie($id, $title, $director, $lang, $minutes, $year, $price, $img_url);

          header("Location: Main.php");
          exit;
        }
      }
    }
  }
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>CINEMA ABSOLUT DATA CENTER - Tambah data</title>
  <link rel="stylesheet" href="style.css">
</head>
<body>
  <main>
    <div class="form-container">
      <h1 class="title">Tambah Data Baru</h1>
      <form method="POST" enctype="multipart/form-data">
        <a href="Main.php" class="button-back">&larr; Kembali</a>
        <div class="input-group">
          <label for="title">Judul<span class="text-danger">*</span></label>
          <input type="text" name="title" id="title" class="<?= $e_idx == 1? "error": "" ?>" value="<?= isset($title)? $title :"" ?>" required>
        </div>
        <div class="input-group">
          <label for="director">Direktor</label>
          <input type="text" name="director" id="director" class="<?= $e_idx == 2? "error": "" ?>" value="<?= isset($director)? $director :"" ?>">
        </div>
        <div class="input-group">
          <label for="lang">Bahasa Dub</label>
          <input type="text" name="lang" id="lang" class="<?= $e_idx == 3? "error": "" ?>" value="<?= isset($lang)? $lang :"" ?>">
        </div>
        <div class="input-group">
          <label for="minutes">Durasi (menit)</label>
          <input type="number" name="minutes" id="minutes" class="<?= $e_idx == 4? "error": "" ?>" min="0" value="<?= isset($minutes)? $minutes :"" ?>">
        </div>
        <div class="input-group">
          <label for="year">Tahun Rilis</label>
          <input type="number" name="year" id="year" class="<?= $e_idx == 5? "error": "" ?>" min="0" value="<?= isset($year)? $year :"" ?>">
        </div>
        <div class="input-group">
          <label for="price">Harga Tiket</label>
          <input type="number" name="price" id="price" class="<?= $e_idx == 6? "error": "" ?>" min="0" value="<?= isset($price)? $price :"" ?>">
        </div>
        <div class="input-group">
          <label for="img">Gambar Promosi</label>
          <input type="file" name="img" id="img" accept="image/*" class="<?= $e_idx == 7? "error": "" ?>">
        </div>
        <?= $e_msg != ""? "<p class=\"text-danger text-end\">".$e_msg."</p>": "" ?>
        <button type="submit" class="button button-submit">TAMBAH</button>
      </form>
    </div>
  </main>
</body>
</html>