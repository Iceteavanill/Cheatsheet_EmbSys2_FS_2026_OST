// Parser (Deserialization) {r:<number>}
int ParseMessage(std::string msg) {
  // check header: {r:
  if (msg[0] != '{' || msg[1] != 'r' || msg[2] != ':') return -1;
  
  // parse digits
  uint8_t nr = 0; int i = 3;
  while (isdigit(msg[i]))
      nr = nr * 10 + (msg[i++] - '0');
  return (msg[i] == '}') ? nr : -1;
}