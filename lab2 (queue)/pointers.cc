int main () {
  int x = 5, y = 15;
  int * p1, *p2;
		// x    5
    // y    15
    // p1   uninit
    // p2   uninit
  p1 = &x;;
		// x    5
    // y    15
    // p1   address of x
    // p2   uninit
  p2 = &y;
    // x    5
    // y    15
    // p1   address of x
    // p2   address of y
  *p1 = 6;
    // x    6
    // y    15
    // p1   address of x
    // p2   address of y
  *p1 = *p2;
    // x    15
    // y    15
    // p1   address of x
    // p2   address of y
  p2 = p1;
    // x    15
    // y    15
    // p1   address of x
    // p2   address of x
  *p1 = *p2+10;
    // x    25
    // y    15
    // p1   address of x
    // p2   address of x
  return 0;
}
