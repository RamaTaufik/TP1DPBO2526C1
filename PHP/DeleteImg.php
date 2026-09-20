<?php
include "Movie.php";

session_start();

// Serupa dengan kode di Delete.php, hanya saja disini proses berhenti pada penghapusan gambar, lalu langsung
// redirect kembali ke Main.php
if(isset($_SESSION["movies"]) && isset($_POST["id"])) {
  $id = (int)$_POST["id"];
  $img = NULL;

  foreach($_SESSION["movies"] as $idx => $movie) {
    if($movie->getId() === $id) {
      $img = $movie->getImgUrl();
      $_SESSION["movies"][$idx]->setImgUrl("-");
      break;
    }
  }

  if($img !== NULL && $img !== "-") {
    $file_path = __DIR__ . '/images/'.$img;

    if(file_exists($file_path)) {
      unlink($file_path);
    }
  }
}

header("Location: Main.php");
exit;