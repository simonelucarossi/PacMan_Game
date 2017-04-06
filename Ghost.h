class Ghost {
private:
	string urlImage;
	int coordinates x,y;
	int** mapShape;
	
public:
	Ghost();
	~Ghost();
	int getCoordinates();
	string getUrlImage();
	void setUrlImage(string);
	void setCoordinateX(int);
	void setCoordinateY(int);
	void MoveLeft(int**);
	void MoveUp(int**);
	void MoveDown(int**);
	void MoveRight(int**);
};