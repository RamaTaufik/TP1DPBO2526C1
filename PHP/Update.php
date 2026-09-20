<?php
include "Movie.php";

session_start();

// Jika laman ini dicoba untuk diakses tanpa mengirim parameter ID lewat metode GET, langsung 'lempar' balik ke laman
// Main.php
if(!isset($_GET["id"])) {
  header("Location: Main.php");
  exit;
}

$id = (int)$_GET["id"];
$movie = NULL;
$e_msg = "";
$e_idx = 0;

// Pastikan session sudah ada, dan jika sudah ada, maka cari data dari record dengan ID yang dikirim
if(!isset($_SESSION["movies"])) {
  $_SESSION["movies"] = [];
} else {
  foreach($_SESSION["movies"] as $m) {
    if($m->getId() === $id) {
      $movie = $m;
      break;
    }
  }
}

// Sama seperti laman Create.php, proses pengubahan data dan merubah data di session dilakukan dalam laman yang sama,
// dibedakan dengan metode. Validasi pun kurang lebih serupa dengan yang ada di laman Create.php
if($_SERVER['REQUEST_METHOD'] === 'POST') {
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
          $img_url = $movie->getImgUrl();
          $id = $movie->getId();

          // Berbeda dengan Create.php, disini ada sedikit proses tambahan pada penambahan gambar, yaitu memastikan
          // gambar sebelumnya dihapus dulu, baru menambahkan gambar yang baru. Tentu, gambar lama hanya akan dihapus
          // jika ada input gambar baru
          if(isset($_FILES['img']) && $_FILES['img']['error'] === UPLOAD_ERR_OK) {
            $img = $_FILES['img'];
            $file_name = 'movie'.$id.'.'.strtolower(pathinfo($img['name'], PATHINFO_EXTENSION));
            $target_dir = __DIR__.'/images/';

            if(!is_dir($target_dir)) {
              mkdir($target_dir, 0755, true);
            }

            $target_path = $target_dir.$file_name;

            if($img_url !== "-") {
              $old_file_path = $target_dir.$img_url;
              if(file_exists($old_file_path)) {
                unlink($old_file_path);
              }
            }
            if(move_uploaded_file($img['tmp_name'], $target_path)) {
              $img_url = $file_name;
            }
          }
          
          foreach($_SESSION["movies"] as $index => $m) {
            if($m->getId() === $id) {
              $_SESSION["movies"][$index] = new Movie($id, $title, $director, $lang, $minutes, $year, $price, $img_url);
              break;
            }
          }

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
  <title>CINEMA ABSOLUT DATA CENTER - Ubah data</title>
  <link rel="stylesheet" href="style.css">
</head>
<body>
  <main>
    <div class="form-container">
      <h1 class="title">Ubah Data</h1>
      <form method="POST" enctype="multipart/form-data">
        <a href="Main.php" class="button-back">&larr; Kembali</a>
        <div class="input-group">
          <label for="title">Judul<span class="text-danger">*</span></label>
          <input type="text" name="title" id="title" class="<?= $e_idx == 1? "error": "" ?>" value="<?= isset($movie)? $movie->getTitle() :"" ?>" required>
        </div>
        <div class="input-group">
          <label for="director">Direktor</label>
          <input type="text" name="director" id="director" class="<?= $e_idx == 2? "error": "" ?>" value="<?= isset($movie)? $movie->getDirector() :"" ?>">
        </div>
        <div class="input-group">
          <label for="lang">Bahasa Dub</label>
          <input type="text" name="lang" id="lang" class="<?= $e_idx == 3? "error": "" ?>" value="<?= isset($movie)? $movie->getLang() :"" ?>">
        </div>
        <div class="input-group">
          <label for="minutes">Durasi (menit)</label>
          <input type="number" name="minutes" id="minutes" class="<?= $e_idx == 4? "error": "" ?>" min="0" value="<?= isset($movie)? $movie->getMinutes() :"" ?>">
        </div>
        <div class="input-group">
          <label for="year">Tahun Rilis</label>
          <input type="number" name="year" id="year" class="<?= $e_idx == 5? "error": "" ?>" min="0" value="<?= isset($movie)? $movie->getYear() :"" ?>">
        </div>
        <div class="input-group">
          <label for="price">Harga Tiket</label>
          <input type="number" name="price" id="price" class="<?= $e_idx == 6? "error": "" ?>" min="0" value="<?= isset($movie)? $movie->getPrice() :"" ?>">
        </div>
        <div class="input-group">
          <label for="img">Gambar Promosi</label>
          <input type="file" name="img" id="img" accept="image/*" class="<?= $e_idx == 7? "error": "" ?>">
        </div>
        <?= $e_msg != ""? "<p class=\"text-danger text-end\">".$e_msg."</p>": "" ?>
        <button type="submit" class="button button-warning">UBAH</button>
      </form>
    </div>
  </main>
</body>
</html>