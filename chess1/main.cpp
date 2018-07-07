#include "piece.h"
#include <iostream>
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
using namespace std;


void creatBoard(piece arr[][8]) {
	piece nothing;
	pawn P;
	rook R;
	knight H;
	bishop B;
	queen Q;
	king K;
	nothing.setDefault(0, 0, 0, '0');
	for (int i=0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			arr[i][j] = nothing;
		}
	}
	for (int i = 0; i < 8; i++) {
		arr[1][i] = P;
		arr[1][i].setDefault(1, i,2,'P');
	}
	for (int i = 0; i < 8; i++) {
		arr[6][i] = P;
		arr[6][i].setDefault(6, i, 1,'P');
	}
	arr[7][0] = arr[7][7] = arr[0][0] = arr[0][7] = R; //set locations of Rooks
	arr[7][0].setDefault(7, 0, 1, 'R');
	arr[7][7].setDefault(7, 7, 1, 'R');
	arr[0][0].setDefault(0, 0, 2, 'R');
	arr[0][7].setDefault(0, 7, 2, 'R');

	arr[7][1] = arr[7][6] = arr[0][1] = arr[0][6] = H; //set locations of knights
	arr[7][1].setDefault(7, 1, 1, 'H');
	arr[7][6].setDefault(7, 6, 1, 'H');
	arr[0][1].setDefault(0, 1, 2, 'H');
	arr[0][6].setDefault(0, 6, 2, 'H');

	arr[7][2] = arr[7][5] = arr[0][2] = arr[0][5] = B; //set locations of Bishops
	arr[7][2].setDefault(7, 2, 1, 'B');
	arr[7][5].setDefault(7, 5, 1, 'B');
	arr[0][2].setDefault(0, 2, 2, 'B');
	arr[0][5].setDefault(0, 5, 2, 'B');

	arr[7][3] = arr[0][3] = Q; //set locations of Queens
	arr[7][3].setDefault(7, 3, 1, 'Q');
	arr[0][3].setDefault(0, 3, 2, 'Q');

	arr[7][4] = arr[0][4] = K; //set locations of kings
	arr[7][4].setDefault(7, 4, 1, 'K');
	arr[0][4].setDefault(0, 4, 2, 'K');
}

void printBoard(piece arr[][8]) {
	char carr[8] = { 'A','B','C','D','E','F','G','H' };
	int iarr[8] = { 1, 2, 3, 4, 5, 6 ,7 ,8 };
	for (int i = 0; i < 8; i++) {
		cout << "\n\n" << " "<< carr[7-i]<<"  ";
		for (int j = 0; j < 8; j++) {
			cout << arr[i][j].type <<arr[i][j].player<< " ";
		}	
	}
	cout << '\n'<<"    ";
	for (int i = 0; i < 8; i++) {
		cout << iarr[i] << "  ";
	}
	cout << '\n';
}


piece select(piece arr[][8],int player,int xl,int yl) {
	piece selected = arr[xl][yl];
	cout << arr[yl][xl].player;
	if (selected.type != '0' && selected.player == player) {
		return selected;
	}
	else {
		cout << "inapplicable selection"<<selected.type;
		selected.type = '0';
		return selected;
	}
}

bool checkConvert(char x, int& y,int& ix) {
	if (toupper(x) >= 'A' && toupper(x) <= 'H' && y > 0 && y <= 8) {
		switch (toupper(x)) {
		case 'A': ix = 7;
			break;
		case 'B': ix = 6;
			break;
		case 'C': ix = 5;
			break;
		case 'D': ix = 4;
			break;
		case 'E': ix = 3;
			break;
		case 'F': ix = 2;
			break;
		case 'G': ix = 1;
			break;
		case 'H': ix = 0;
			break;
		}
		y = y - 1;
		return true;
	}
	else {
		cout << "inapplicable selection1";
		return false;
	}
}

bool canMove(piece arr[][8], piece obj, int x, int y,int player) {
	//accesses if space is empty
	if (arr[x][y].type == '0') {
		//sets movement for pawn
		if (obj.type == 'P') {
			pawn p;
			p.setDefault(obj.locationX, obj.locationY, obj.player,obj.type);
			return p.moveApplicable(x, y);
		}
		// sets movement for rook
		if (obj.type == 'R') {
			rook r;
			r.setDefault(obj.locationX, obj.locationY, obj.player, obj.type);
			return r.moveApplicable(x, y);
		}
		// sets movement for knight
		if (obj.type == 'H') {
			knight k;
			k.setDefault(obj.locationX, obj.locationY, obj.player, obj.type);
			return k.moveApplicable(x, y);
		}
		// sets movement for bishop
		if (obj.type == 'B') {
			bishop b;
			b.setDefault(obj.locationX, obj.locationY, obj.player, obj.type);
			return b.moveApplicable(x, y);
		}
		// sets movement for queen
		if (obj.type == 'Q') {
			queen q;
			q.setDefault(obj.locationX, obj.locationY, obj.player, obj.type);
			return q.moveApplicable(x, y);
		}
		// sets movement for king
		if (obj.type == 'K') {
			king k;
			k.setDefault(obj.locationX, obj.locationY, obj.player, obj.type);
			return k.moveApplicable(x, y);
		}
	}
	// access to see if enemy character is in spot
	else if(arr[x][y].player != player) {
		//sets pawn attack
		if (obj.type == 'P') {
			pawn p;
			p.setDefault(obj.locationX, obj.locationY, obj.player,obj.type);
			return p.attackApplicable(x, y);
		}
		//sets rook attack
		if (obj.type == 'R') {
			rook r;
			r.setDefault(obj.locationX, obj.locationY, obj.player, obj.type);
			return r.attackApplicable(x, y);
		}
		//sets knight attack
		if (obj.type == 'H') {
			knight k;
			k.setDefault(obj.locationX, obj.locationY, obj.player, obj.type);
			return k.attackApplicable(x, y);
		}
		//sets bishop attack
		if (obj.type == 'B') {
			bishop b;
			b.setDefault(obj.locationX, obj.locationY, obj.player, obj.type);
			return b.attackApplicable(x, y);
		}
		if (obj.type == 'Q') {
			queen q;
			q.setDefault(obj.locationX, obj.locationY, obj.player, obj.type);
			return q.attackApplicable(x, y);
		}
	}
	else {
		cout << "Movement unaviable";
		return false;
	}
}

int main() {

	piece board[8][8];
	piece selectedPiece;
	piece nothing;
	creatBoard(board);
	int player = 1;
	char selectX;
	int selectY,iselectX;
	char moveX;
	int moveY,imoveX;
	bool works,moved,movePassed;
	while (true) {
		printBoard(board);
		moved = false;
			

				cout << "Player " << player << " turn" << '\n';
				cout << "Please select piece by entering location (A-H) and (1-8)";
				cin >> selectX >> selectY;

				works = checkConvert(selectX, selectY,iselectX);
				if (works) {
					selectedPiece = select(board, player, iselectX, selectY);
					if (selectedPiece.type != '0') {
						cout << "Please select movement location (A-H) and (1-8)" << '\n';
						cin >> moveX >> moveY;
						works = checkConvert(moveX, moveY,imoveX);

						if (works) {
							movePassed=canMove(board, selectedPiece, imoveX, moveY, player);
							if (movePassed) {
								
								board[imoveX][moveY]=selectedPiece;
								board[selectedPiece.locationX][selectedPiece.locationY] = nothing;
								board[imoveX][moveY].setLocation(imoveX, moveY);
							}
						}
					}

				}

			


		if (player == 1) {
			player = 2;
		}
		else {
			player = 1;
		}

	}


	return 0;
}