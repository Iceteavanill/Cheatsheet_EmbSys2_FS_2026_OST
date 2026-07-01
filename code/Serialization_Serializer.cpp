// Serializer
char buf[64]; // ts, temp in RAM
sprintf(buf, "{d:%lu,%.2f}", ts, temp);
cp->Transmit((uint8_t*)buf, strlen(buf));