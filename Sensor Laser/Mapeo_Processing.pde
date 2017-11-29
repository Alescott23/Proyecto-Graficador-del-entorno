void setup()
{
  size(1200, 700);
}

void draw()
{
  if (mouseX==0) {
    background(0);
  }
  stroke(0, 0, 0, 200);
  strokeWeight(10);
  pushMatrix();
  translate(width/2, 10);
  rotate(HALF_PI-mouseX*PI/180);
  line(0, 0, 0, 800);
  stroke(255, 0, 0, 200);
  point(0,mouseY*3);
  popMatrix();
 }