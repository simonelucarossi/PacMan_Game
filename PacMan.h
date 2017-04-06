class PacMan{
	private:
	string urlImage;
	int coordinates x,y;
	int** mapShape;
	
public:
	PacMan();
	~PacMan();
	int getCoordinates();
	string getUrlImage();
	void setUrlImage(string);
	void setCoordinateX(int);
	void setCoordinateY(int);
	void MoveLeft(int**);
	void MoveUp(int**);
	void MoveDown(int**);
	void MoveRight(int**);
	bool CheckCollision(int **, Ghost*);
};