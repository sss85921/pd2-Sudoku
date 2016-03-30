class Sudoku{
	public:
		void giveQuestion();
		void readIn();
		void solve();
		void change();
		void changeNum(int a, int b);
		void changeRow(int a, int b);
		void changeCol(int a,int b);
		void rotate(int n);
		void flip(int n);
		void transform();
};
