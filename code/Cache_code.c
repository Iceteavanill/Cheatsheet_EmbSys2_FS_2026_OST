for (int col = 0; col < 256; col++){
    for (int row = 0;row<256; row++)
        result += *(data + row*256 + col);
} // Unfriendly

for (int row = 0; row < 256; row++){
    for (int col = 0;col<256; col++)
        result += *(data + row*256 + col);
} // friendly