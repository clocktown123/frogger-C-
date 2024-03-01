
//movement function: can move left or right
//resets position to other side when moves offscreen
void car::move() {
	if (directionG == LEFT) {
		if (xpos < -100)
			xpos = 1100;
		xpos -= .1;
	}

	else if (directionG == RIGHT) {
		if (xpos > 1100)
			xpos = -100;
		xpos += .1;
	}

}

bool car::collide(int x, int y) {
	if (xpos + 100 > x && xpos <= x && ypos + 50 > y && ypos <= y) {
		cout << "dead" << endl;
		return true;
	}
	else
		return false;

}
