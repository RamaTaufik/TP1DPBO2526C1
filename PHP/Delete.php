<?php
include "Movie.php";

session_start();

// Pastikan data session ada dan ID dikirim lewat metode POST
if(isset($_SESSION["movies"]) && isset($_POST["id"])) {
  $id = (int)$_POST["id"]; // Secara default data selalu dikirim dalam bentuk string, sehingga ubah lagi ke integer
  $img = NULL;

  // Cari record yang ingin dihapus dari ID-nya
  foreach($_SESSION["movies"] as $movie) {
    if($movie->getId() === $id) {
      $img = $movie->getImgUrl();
      break;
    }
  }

  // Hapus terlebih dahulu gambar record tersebut di direktori lokal jika ada
  if($img !== NULL && $img !== "-") {
    $file_path = __DIR__ . '/images/'.$img;

    if(file_exists($file_path)) {
      unlink($file_path);
    }
  }

  // Baru hilangkan record
  $_SESSION["movies"] = array_filter($_SESSION["movies"], fn($movie) => $movie->getId() !== $id);
}

// Redirect kembali ke Main.php
header("Location: Main.php");
exit;