<?php
include "Movie.php";

session_start();

if(isset($_SESSION["movies"]) && isset($_POST["id"])) {
  $id = (int)$_POST["id"];
  $img = NULL;

  foreach($_SESSION["movies"] as $movie) {
    if($movie->getId() === $id) {
      $img = $movie->getImgUrl();
      break;
    }
  }

  if($img !== NULL && $img !== "-") {
    $file_path = __DIR__ . '/images/'.$img;

    if(file_exists($file_path)) {
      unlink($file_path);
    }
  }

  $_SESSION["movies"] = array_filter($_SESSION["movies"], fn($movie) => $movie->getId() !== $id);
}

header("Location: Main.php");
exit;