
void killAudio() {
  system("kill -9 ");
}

void startAudio() {

  pid_t x;
  x = fork();

  if (x < 0)
    puts("ERR: fork failure");
  else if (x == 0)
    execlp("mpg123", "mpg123", "-q", "./lpwu.mp3", 0);
}
