<?php

class Movie {
  private string $title, $director, $lang, $img_url;
  private int $id, $minutes, $year, $price;

  public function __construct(int $id, string $t, string $d, string $l, int $m, int $y, int $p, string $i) {
    $this->setId($id);
    $this->setTitle($t);
    $this->setDirector($d);
    $this->setLang($l);
    $this->setMinutes($m);
    $this->setYear($y);
    $this->setPrice($p);
    $this->setImgUrl($i);
  }

  public function setId(int $id): void {
    $this->id = $id;
  }
  public function getId(): int {
    return $this->id;
  }

  public function setTitle(string $t): void {
    $this->title = $t;
  }
  public function getTitle(): string {
    return $this->title;
  }

  public function setDirector(string $d): void {
    if ($d === "") {
      $this->director = "-";
    } else {
      $this->director = $d;
    }
  }
  public function getDirector(): string {
    return $this->director;
  }

  public function setLang(string $l): void {
    if ($l === "") {
      $this->lang = "-";
    } else {
      $this->lang = $l;
    }
  }
  public function getLang(): string {
    return $this->lang;
  }

  public function setMinutes(int $m): void {
    $this->minutes = $m;
  }
  public function getMinutes(): int {
    return $this->minutes;
  }

  public function setYear(int $y): void {
    $this->year = $y;
  }
  public function getYear(): int {
    return $this->year;
  }

  public function setPrice(int $p): void {
    $this->price = $p;
  }
  public function getPrice(): int {
    return $this->price;
  }

  public function setImgUrl(string $i): void {
    if ($i === "") {
      $this->img_url = "-";
    } else {
      $this->img_url = $i;
    }
  }
  public function getImgUrl(): string {
    return $this->img_url;
  }
}