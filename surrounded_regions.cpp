struct Point{
	int x, y;
	Point(int a, int b): x(a), y(b){}
};
void solve(vector<vector<char>> &board) {
	if(board.size()<=1) return;
	// use BSF to store the boundary-connecting points
	vector<Point> points;
	int rows = board.size(); int cols = board[0].size();
	for(int i=0; i<rows; i++) {
		if(board[i][0]=='O') { 
			points.push_back(Point(i, 0));
			board[i][0] = 'Y';
		}
		if(board[i][cols-1]=='O') {
			points.push_back(Point(i, cols-1));
			board[i][cols-1] = 'Y';
		}
	}
	for(int j=1; j<cols-1; j++) {
		if(board[0][j]=='O'){
			points.push_back(Point(0, j));
			board[0][j] = 'Y';
		}
		if(board[rows-1][j]=='O') {
			points.push_back(Point(rows-1,j));
			board[rows-1][j]='Y';
		}
	}
	while(!points.empty()) {
		Point p = points[0]; points.erase(points.begin());
		int x = p.x; int y = p.y;
		if(x+1<rows-1 && board[x+1][y]=='O') {
			points.push_back(Point(x+1, y));
			board[x+1][y]='Y';
		}
		if(x-1>0 && board[x-1][y]=='O') {
			points.push_back(Point(x-1, y));
			board[x-1][y]='Y';
		}
		if(y+1<cols-1 && board[x][y+1]=='O') {
			points.push_back(Point(x, y+1));
			board[x][y+1] = 'Y';
		}
		if(y-1>0 && board[x][y-1]=='O') {
			points.push_back(Point(x, y-1));
			board[x][y-1]= 'Y';
		}
	}
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			if(board[i][j]=='O') board[i][j] = 'X';
			if(board[i][j]=='Y') board[i][j] = 'O';
		}
	}
}
