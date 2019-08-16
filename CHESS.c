#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define bp 11
#define br 12
#define bkn 13
#define bb 14
#define bq 16
#define bk 15
#define wp 21
#define wr 22
#define wkn 23
#define wb 24
#define wq 26
#define wk 25
void board(void);
void p1pos(int t);
int getsx(int x);
int getsy(int y);
void p2pos(int t);
void clearpos(int x, int y);
static int b_ar[8][8];
char c1[5] = "wK",c2[5] = "wQ",c3[5] = "wR",c4[5] = "wKN",c5[5] = "wB";
char c6[5] = "wP";
char c7[5]="bK",c8[5]="bQ",c9[5]="bR",c10[5]="bKN",c11[5]="bB";
char c12[5] = "bP";
void def_b_ar(void);
void viewvirtualboard(void);
int checkpiece(int i, int j);
void Bpawn(int curx, int cury, int nx, int ny);
void Wpawn(int curx, int cury, int nx, int ny);
void Brook(int curx, int cury, int nx, int ny);
void Wrook(int curx, int cury, int nx, int ny);
void Bbishop(int curx, int cury, int nx, int ny);
void Wbishop(int curx, int cury, int nx, int ny);
void Bqueen(int curx, int cury, int nx, int ny);
void Wqueen(int curx, int cury, int nx, int ny);
void Bking(int curx, int cury, int nx, int ny);
void Wking(int curx, int cury, int nx, int ny);
void Bknight(int curx, int cury, int nx, int ny);
void Wknight(int curx, int cury, int nx, int ny);
int chkwin(void);
int main(){
	int curx, cury, nx, ny, w, sp, op;
	restart:
	clrscr();
	w = 21;
	def_b_ar();
	board();
	while(w==21){
		p1:
		w = chkwin();
		if(w!=21){
			break;
		}
		else{
			p1pos(1);
			scanf("%d%d",&curx,&cury);
			p1pos(0);
			scanf("%d%d",&nx,&ny);
			sp = checkpiece(curx,cury);
			switch(sp){
				case 11:	Bpawn(curx,cury,nx,ny);
						break;
				case 12:        Brook(curx,cury,nx,ny);
						break;
				case 13:        Bknight(curx,cury,nx,ny);
						break;
				case 14:        Bbishop(curx,cury,nx,ny);
						break;
				case 15:        Bking(curx,cury,nx,ny);
						break;
				case 16:        Bqueen(curx,cury,nx,ny);
						break;
				default:	goto p1;
			}
		}
		p2:
		w = chkwin();
		if(w!=21){
			break;
		}
		else{
			p2pos(1);
			scanf("%d%d",&curx,&cury);
			p2pos(0);
			scanf("%d%d",&nx,&ny);
			sp = checkpiece(curx,cury);
			switch(sp){
				case 21:	Wpawn(curx,cury,nx,ny);
						break;
				case 22:        Wrook(curx,cury,nx,ny);
						break;
				case 23:        Wknight(curx,cury,nx,ny);
						break;
				case 24:        Wbishop(curx,cury,nx,ny);
						break;
				case 25:        Wking(curx,cury,nx,ny);
						break;
				case 26:        Wqueen(curx,cury,nx,ny);
						break;
				default:	goto p2;
			}
		}
		w = chkwin();
		if(w!=21){
			break;
		}
	}
	clrscr();
	if(w==10){
		gotoxy(40,9);
		printf("PLAYER 1 WINS !!!\n\n");
		printf("\t\t\tPRESS 1 TO PLAY AGAIN OR 0 TO EXIT\n\n\t\t\t");
		scanf("%d",&op);
		switch(op){
			case 1:	goto restart;
			case 0:	exit(0);
		}
	}
	else{
		gotoxy(40,9);
		printf("PLAYER 2 WINS !!!\n\n");
		printf("\t\t\tPRESS 1 TO PLAY AGAIN OR 0 TO EXIT\n\n\t\t\t");
		scanf("%d",&op);
		switch(op){
			case 1:	goto restart;
			case 0:	exit(0);
		}
	}
	getch();
	return 0;
}
/*Function to check if either of player has won	searches
the chess board for both kings if either black or white
king is not found the other player wins
*/
int chkwin(void){
	int i,j,b=0;
	for(i=1;i<=8;i++){
		for(j=1;j<=8;j++){
			if(b_ar[i][j]==bk){
				b=10;
				break;
			}
		}
	}
	for(i=1;i<=8;i++){
		for(j=1;j<=8;j++){
			if(b_ar[i][j]==wk){
				b+=11;
				break;
			}
		}
	}
	return b;
}
/*Just a function that helped debugging and stuff. Functionality is
pretty much self explainatory just read the name of the function
*/
void viewvirtualboard(void){
	int i,j;
	for(i=1;i<=8;i++){
		for(j=1;j<=8;j++){
			printf("%d ",b_ar[i][j]);
		}
		printf("\n");
	}
}
/*Function to draw the board on the user screen
goes without saying it only works in Turbo C
*/
void board(void){
	int i,j=0,y=2,k=1;
	for(i=22;i<62;i+=5){
		gotoxy(i,1);
		printf("%d",k);
		k++;
	}
	k=1;
	while(j!=8){
		if(j==0){
			gotoxy(20,y);
			for(i=1;i<41;i++){
				printf("_");
			}
		}
		++y;
		gotoxy(20,y);
		for(i=0;i<8;i++){
			if(i==7){
				printf("|    |");
			}
			else{
				printf("|    ");
			}
		}
		++y;
		gotoxy(20,y);
		for(i=0;i<8;i++){
			if(i==7){
				printf("|____|");
			}
			else{
				printf("|____");
			}
		}
		j++;
	}
	for(i=22;i<62;i+=5){
		gotoxy(i,19);
		printf("%d",k);
		k++;
	}
	k=1;
	for(i=3;i<18;i+=2){
		gotoxy(18,i);
		printf("%d",k);
		k++;
	}
	k=1;
	for(i=3;i<18;i+=2){
		gotoxy(62,i);
		printf("%d",k);
		k++;
	}
	for(i=1;i<=80;i++){
		gotoxy(i,20);
		printf("_");
	}
	printf("PLAYER 1 (BLACK, TOP)      \t\t\tPLAYER 2  (WHITE, BOTTOM)       ");
	printf("ENTER SELECTED PIECE :\t\t\t\tENTER SELECTED PIECE :\n");
	printf("ENTER POSITION :\t\t\t\tENTER POSITION :");
	for(i=21;i<26;i++){
		gotoxy(40,i);
		printf("|");
	}
	for(i=22;i<=57;i+=5){
		gotoxy(i,3);
		if((i==22)||(i==57)){
			printf("%s",c9);
		}
		else
		if((i==27)||(i==52)){
			printf("%s",c10);
		}
		else
		if((i==32)||(i==47)){
			printf("%s",c11);
		}
		else
		if(i==37){
			printf("%s",c7);
		}
		else
		if(i==42){
			printf("%s",c8);
		}
	}
	for(i=22;i<=57;i+=5){
		gotoxy(i,5);
		printf("%s",c12);
	}
	for(i=22;i<=57;i+=5){
		gotoxy(i,17);
		if((i==22)||(i==57)){
			printf("%s",c3);
		}
		else
		if((i==27)||(i==52)){
			printf("%s",c4);
		}
		else
		if((i==32)||(i==47)){
			printf("%s",c5);
		}
		else
		if(i==37){
			printf("%s",c1);
		}
		else
		if(i==42){
			printf("%s",c2);
		}
	}
	for(i=22;i<=57;i+=5){
		gotoxy(i,15);
		printf("%s",c6);
	}
	p1pos(1);
}
//Function to switch turns from player 2 to player 1
void p1pos(int t){
	if(t==1){
		gotoxy(71,23);
		printf("    ");
		gotoxy(72,23);
		gotoxy(71,22);
		printf("    ");
		gotoxy(72,22);
		gotoxy(24,23);
		printf("    ");
		gotoxy(25,23);
		gotoxy(24,22);
		printf("    ");
		gotoxy(25,22);
	}
	else{
		gotoxy(71,23);
		printf("    ");
		gotoxy(72,23);
		gotoxy(71,22);
		printf("    ");
		gotoxy(72,22);
		gotoxy(24,22);
		printf("    ");
		gotoxy(25,22);
		gotoxy(24,23);
		printf("    ");
		gotoxy(25,23);
	}
}
// Function to switch turn from player 1 to player 2
void p2pos(int t){
	if(t==1){
		gotoxy(24,23);
		printf("    ");
		gotoxy(25,23);
		gotoxy(24,22);
		printf("    ");
		gotoxy(25,22);
		gotoxy(71,23);
		printf("    ");
		gotoxy(72,23);
		gotoxy(71,22);
		printf("    ");
		gotoxy(72,22);
	}
	else{
		gotoxy(24,23);
		printf("    ");
		gotoxy(25,23);
		gotoxy(24,22);
		printf("    ");
		gotoxy(25,22);
		gotoxy(71,22);
		printf("    ");
		gotoxy(72,22);
		gotoxy(71,23);
		printf("    ");
		gotoxy(72,23);
	}
}
/*Function to define the initial state of board array Places
int codes assigned to chess pieces at their individual positions
in the array
*/
void def_b_ar(void){
	int i,j;
	for(j=1;j<=8;j++){
		switch(j){
			case 1: b_ar[1][j] = br;
				b_ar[2][j] = bp;
				b_ar[8][j] = wr;
				b_ar[7][j] = wp;
				break;
			case 2: b_ar[1][j] = bkn;
				b_ar[2][j] = bp;
				b_ar[8][j] = wkn;
				b_ar[7][j] = wp;
				break;
			case 3: b_ar[1][j] = bb;
				b_ar[2][j] = bp;
				b_ar[8][j] = wb;
				b_ar[7][j] = wp;
				break;
			case 4: b_ar[1][j] = bk;
				b_ar[2][j] = bp;
				b_ar[8][j] = wk;
				b_ar[7][j] = wp;
				break;
			case 5: b_ar[1][j] = bq;
				b_ar[2][j] = bp;
				b_ar[8][j] = wq;
				b_ar[7][j] = wp;
				break;
			case 6: b_ar[1][j] = bb;
				b_ar[2][j] = bp;
				b_ar[8][j] = wb;
				b_ar[7][j] = wp;
				break;
			case 7: b_ar[1][j] = bkn;
				b_ar[2][j] = bp;
				b_ar[8][j] = wkn;
				b_ar[7][j] = wp;
				break;
			case 8: b_ar[1][j] = br;
				b_ar[2][j] = bp;
				b_ar[8][j] = wr;
				b_ar[7][j] = wp;
				break;
		}
	}
}
/*Function to check which piece is present at i,j position,
returns piece code associated with the chess piece
*/
int checkpiece(int i, int j){
	int val;
	val = b_ar[i][j];
	return val;
}
/*Function to clear anything at the x,y position on the user screen
Used to move pieces on the user screen removing the chess piece from
it's previous position
*/
void clearpos(int x, int y){
	int i,j,thy=3,thx;
	for(i=1;i<=8;i++){
		thx = 22;
		for(j=1;j<=8;j++){
			if((x==i)&&(y==j)){
				gotoxy(thx,thy);
				printf("   ");
				break;
			}
			thx+=5;
		}
		thy+=2;
	}
}
/*Function to returned scaled value of x or ith position in the array
used to clear and move things on user screen say, if user wants to move the
piece at 2,4 this function returns the scaled value of x or 2 in this
case, as to where the piece is at on the user screen
*/
int getsx(int x){
	int j,thx=22;
	for(j=1;j<=8;j++){
		if(x==j){
			break;
		}
		else{
			thx+=5;
		}
	}
	return thx;
}
/*Function to returned scaled value of y or jth position in the array
used to clear and move things on user screen say, if user wants to move the
piece at 2,4 this function returns the scaled value of y or 4 in this
case, as to where the piece is at on the user screen
*/
int getsy(int y){
	int j,thy=3;
	for(j=1;j<=8;j++){
		if(y==j){
			break;
		}
		else{
			thy+=2;
		}
	}
	return thy;
}
/*Function to be called when the player chooses to move a black pawn
used to make sure the move is legal and if legal then changes things
on user screen and virtual board array
*/
void Bpawn(int curx, int cury, int nx, int ny){
	int p;
	if((nx==curx+1)||(nx==curx+2)){
		if(nx==curx+1){
			if(ny==cury){
				p = checkpiece(nx,ny);
				if(p==0){
					b_ar[nx][ny]=bp;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);
					delay(500);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c12);
				}
			}
			else
			if((ny==cury-1)||(ny==cury+1)){
				p = checkpiece(nx,ny);
				if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
					b_ar[nx][ny]=bp;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);
					delay(500);
					clearpos(nx,ny);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c12);
				}
			}
		}
		else
		if(nx==curx+2){
			p = checkpiece(nx,ny);
			if((curx>2)||(ny!=cury)){
				goto here;
			}
			if(p==0){
				b_ar[nx][ny]=bp;
				b_ar[curx][cury]=0;
				clearpos(curx,cury);
				delay(500);
				gotoxy(getsx(ny),getsy(nx));
				printf("%s",c12);
			}
		}
	}
	else{
		here:
		gotoxy(2,10);
		printf("INVALID MOVE!!");
		gotoxy(66,10);
		printf("INVALID MOVE!!");
		delay(500);
		gotoxy(2,10);
		printf("              ");
		gotoxy(66,10);
		printf("              ");
	}
}
/*Function to be called when the player chooses to move a white pawn
used to make sure the move is legal and if legal then changes things
on user screen and virtual board array
*/
void Wpawn(int curx, int cury, int nx, int ny){
	int p;
	if((nx==curx-1)||(nx==curx-2)){
		if(nx==curx-1){
			if(ny==cury){
				p = checkpiece(nx,ny);
				if(p==0){
					b_ar[nx][ny]=wp;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);
					delay(500);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c6);
				}
			}
			else
			if((ny==cury-1)||(ny==cury+1)){
				p = checkpiece(nx,ny);
				if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
					b_ar[nx][ny]=wp;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);
					delay(500);
					clearpos(nx,ny);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c6);
				}
			}
		}
		else
		if(nx==curx-2){
			p = checkpiece(nx,ny);
			if((curx<7)||(ny!=cury)){
				goto here;
			}
			if(p==0){
				b_ar[nx][ny]=wp;
				b_ar[curx][cury]=0;
				clearpos(curx,cury);
				delay(500);
				gotoxy(getsx(ny),getsy(nx));
				printf("%s",c6);
			}
		}
	}
	else{
		here:
		gotoxy(2,10);
		printf("INVALID MOVE!!");
		gotoxy(66,10);
		printf("INVALID MOVE!!");
		delay(500);
		gotoxy(2,10);
		printf("              ");
		gotoxy(66,10);
		printf("              ");
	}
}
/*Function to be called when the player chooses to move a black rook
used to make sure the move is legal and if legal then changes things
on user screen and virtual board array
*/
void Brook(int curx, int cury, int nx, int ny){
	int i,p;
	if(curx==nx){
		if(ny>cury){
			for(i=cury+1;i<=ny;i++){
				if(i==ny){
					p = checkpiece(nx,i);
					if(p==0){
						b_ar[nx][ny]=br;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c9);
					}
					else
					if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
						b_ar[nx][ny]=br;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						clearpos(nx,ny);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c9);
					}
					else{
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
					}
				}
				else{
					p = checkpiece(nx,i);
					if(p!=0){
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
						break;
					}
				}
			}
		}
		else
		if(ny<cury){
			for(i=cury-1;i>=ny;i--){
				if(i==ny){
					p = checkpiece(nx,i);
					if(p==0){
						b_ar[nx][ny]=br;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c9);
					}
					else
					if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
						b_ar[nx][ny]=br;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						clearpos(nx,ny);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c9);
					}
					else{
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
					}
				}
				else{
					p = checkpiece(nx,i);
					if(p!=0){
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
						break;
					}
				}
			}
		}
	}
	else
	if(cury==ny){
		if(nx>curx){
			for(i=curx+1;i<=nx;i++){
				if(i==nx){
					p = checkpiece(i,ny);
					if(p==0){
						b_ar[nx][ny]=br;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c9);
					}
					else
					if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
						b_ar[nx][ny]=br;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						clearpos(nx,ny);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c9);
					}
					else{
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
					}
				}
				else{
					p = checkpiece(i,ny);
					if(p!=0){
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
						break;
					}
				}
			}
		}
		else
		if(nx<curx){
			 for(i=curx-1;i>=nx;i--){
				if(i==nx){
					p = checkpiece(i,ny);
					if(p==0){
						b_ar[nx][ny]=br;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c9);
					}
					else
					if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
						b_ar[nx][ny]=br;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						clearpos(nx,ny);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c9);
					}
					else{
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
					}
				}
				else{
					p = checkpiece(i,ny);
					if(p!=0){
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
						break;
					}
				}
			}
		}
	}
	else{
		gotoxy(2,10);
		printf("INVALID MOVE!!");
		gotoxy(66,10);
		printf("INVALID MOVE!!");
		delay(500);
		gotoxy(2,10);
		printf("              ");
		gotoxy(66,10);
		printf("              ");
	}
}
/*Function to be called when the player chooses to move a white rook
used to make sure the move is legal and if legal then changes things
on user screen and virtual board array
*/
void Wrook(int curx, int cury, int nx, int ny){
	int i,p;
	if(curx==nx){
		if(ny>cury){
			for(i=cury+1;i<=ny;i++){
				if(i==ny){
					p = checkpiece(nx,i);
					if(p==0){
						b_ar[nx][ny]=wr;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c3);
					}
					else
					if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
						b_ar[nx][ny]=wr;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						clearpos(nx,ny);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c3);
					}
					else{
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
					}
				}
				else{
					p = checkpiece(nx,i);
					if(p!=0){
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
						break;
					}
				}
			}
		}
		else
		if(ny<cury){
			for(i=cury-1;i>=ny;i--){
				if(i==ny){
					p = checkpiece(nx,i);
					if(p==0){
						b_ar[nx][ny]=wr;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c3);
					}
					else
					if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
						b_ar[nx][ny]=wr;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						clearpos(nx,ny);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c3);
					}
					else{
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
					}
				}
				else{
					p = checkpiece(nx,i);
					if(p!=0){
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
						break;
					}
				}
			}
		}
	}
	else
	if(cury==ny){
		if(nx>curx){
			for(i=curx+1;i<=nx;i++){
				if(i==nx){
					p = checkpiece(i,ny);
					if(p==0){
						b_ar[nx][ny]=wr;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c3);
					}
					else
					if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
						b_ar[nx][ny]=wr;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						clearpos(nx,ny);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c3);
					}
					else{
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
					}
				}
				else{
					p = checkpiece(i,ny);
					if(p!=0){
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
						break;
					}
				}
			}
		}
		else
		if(nx<curx){
			 for(i=curx-1;i>=nx;i--){
				if(i==nx){
					p = checkpiece(i,ny);
					if(p==0){
						b_ar[nx][ny]=wr;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c3);
					}
					else
					if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
						b_ar[nx][ny]=wr;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						clearpos(nx,ny);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c3);
					}
					else{
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
					}
				}
				else{
					p = checkpiece(i,ny);
					if(p!=0){
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
						break;
					}
				}
			}
		}
	}
	else{
		gotoxy(2,10);
		printf("INVALID MOVE!!");
		gotoxy(66,10);
		printf("INVALID MOVE!!");
		delay(500);
		gotoxy(2,10);
		printf("              ");
		gotoxy(66,10);
		printf("              ");
	}
}
/*Function to be called when the player chooses to move a black bishop
used to make sure the move is legal and if legal then changes things
on user screen and virtual board array
*/
void Bbishop(int curx, int cury, int nx, int ny){
	int i,p;
	if((nx>curx)&&(ny>cury)){
		for(i=1;i<=8;i++){
			if((nx==curx+i)&&(ny==cury+i)){
				p = checkpiece(nx,ny);
				if(p==0){
					b_ar[nx][ny]=bb;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);
					delay(500);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c11);
				}
				else
				if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
					b_ar[nx][ny]=bb;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);						delay(500);
					clearpos(nx,ny);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c11);
				}
				else{
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
				}
				break;
			}
			else{
				p = checkpiece(curx+i,cury+i);
				if(p!=0){
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
					break;
				}
			}
		}
	}
	else
	if((nx<curx)&&(ny<cury)){
		for(i=1;i<=8;i++){
			if((nx==curx-i)&&(ny==cury-i)){
				p = checkpiece(nx,ny);
				if(p==0){
					b_ar[nx][ny]=bb;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);
					delay(500);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c11);
				}
				else
				if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
					b_ar[nx][ny]=bb;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);						delay(500);
					clearpos(nx,ny);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c11);
				}
				else{
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
				}
				break;
			}
			else{
				p = checkpiece(curx-i,cury-i);
				if(p!=0){
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
					break;
				}
			}
		}
	}
	else
	if((nx>curx)&&(ny<cury)){
		for(i=1;i<=8;i++){
			if((curx+i==nx)&&(cury-i==ny)){
				p = checkpiece(nx,ny);
				if(p==0){
					b_ar[nx][ny]=bb;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);
					delay(500);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c11);
				}
				else
				if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
					b_ar[nx][ny]=bb;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);						delay(500);
					clearpos(nx,ny);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c11);
				}
				else{
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
				}
				break;
			}
			else{
				p = checkpiece(curx+i,cury-i);
				if(p!=0){
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
					break;
				}
			}
		}
	}
	else
	if((nx<curx)&&(ny>cury)){
		for(i=1;i<=8;i++){
			if((curx-i==nx)&&(cury+i==ny)){
				p = checkpiece(nx,ny);
				if(p==0){
					b_ar[nx][ny]=bb;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);
					delay(500);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c11);
				}
				else
				if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
					b_ar[nx][ny]=bb;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);						delay(500);
					clearpos(nx,ny);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c11);
				}
				else{
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
				}
				break;
			}
			else{
				p = checkpiece(curx-i,cury+i);
				if(p!=0){
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
					break;
				}
			}
		}
	}
	else{
		gotoxy(2,10);
		printf("INVALID MOVE!!");
		gotoxy(66,10);
		printf("INVALID MOVE!!");
		delay(500);
		gotoxy(2,10);
		printf("              ");
		gotoxy(66,10);
		printf("              ");
	}
}
/*Function to be called when the player chooses to move a white bishop
used to make sure the move is legal and if legal then changes things
on user screen and virtual board array
*/
void Wbishop(int curx, int cury, int nx, int ny){
	int i,p;
	if((nx>curx)&&(ny>cury)){
		for(i=1;i<=8;i++){
			if((nx==curx+i)&&(ny==cury+i)){
				p = checkpiece(nx,ny);
				if(p==0){
					b_ar[nx][ny]=wb;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);
					delay(500);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c5);
				}
				else
				if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
					b_ar[nx][ny]=wb;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);						delay(500);
					clearpos(nx,ny);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c5);
				}
				else{
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
				}
				break;
			}
			else{
				p = checkpiece(curx+i,cury+i);
				if(p!=0){
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
					break;
				}
			}
		}
	}
	else
	if((nx<curx)&&(ny<cury)){
		for(i=1;i<=8;i++){
			if((nx==curx-i)&&(ny==cury-i)){
				p = checkpiece(nx,ny);
				if(p==0){
					b_ar[nx][ny]=wb;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);
					delay(500);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c5);
				}
				else
				if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
					b_ar[nx][ny]=wb;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);						delay(500);
					clearpos(nx,ny);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c5);
				}
				else{
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
				}
				break;
			}
			else{
				p = checkpiece(curx-i,cury-i);
				if(p!=0){
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
					break;
				}
			}
		}
	}
	else
	if((nx>curx)&&(ny<cury)){
		for(i=1;i<=8;i++){
			if((curx+i==nx)&&(cury-i==ny)){
				p = checkpiece(nx,ny);
				if(p==0){
					b_ar[nx][ny]=wb;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);
					delay(500);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c5);
				}
				else
				if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
					b_ar[nx][ny]=wb;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);						delay(500);
					clearpos(nx,ny);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c5);
				}
				else{
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
				}
				break;
			}
			else{
				p = checkpiece(curx+i,cury-i);
				if(p!=0){
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
					break;
				}
			}
		}
	}
	else
	if((nx<curx)&&(ny>cury)){
		for(i=1;i<=8;i++){
			if((curx-i==nx)&&(cury+i==ny)){
				p = checkpiece(nx,ny);
				if(p==0){
					b_ar[nx][ny]=wb;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);
					delay(500);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c5);
				}
				else
				if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
					b_ar[nx][ny]=wb;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);						delay(500);
					clearpos(nx,ny);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c5);
				}
				else{
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
				}
				break;
			}
			else{
				p = checkpiece(curx-i,cury+i);
				if(p!=0){
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
					break;
				}
			}
		}
	}
	else{
		gotoxy(2,10);
		printf("INVALID MOVE!!");
		gotoxy(66,10);
		printf("INVALID MOVE!!");
		delay(500);
		gotoxy(2,10);
		printf("              ");
		gotoxy(66,10);
		printf("              ");
	}
}
/*Function to be called when the player chooses to move a black queen
used to make sure the move is legal and if legal then changes things
on user screen and virtual board array
*/
void Bqueen(int curx, int cury, int nx, int ny){
	int i,p;
	if(curx==nx){
		if(ny>cury){
			for(i=cury+1;i<=ny;i++){
				if(i==ny){
					p = checkpiece(nx,i);
					if(p==0){
						b_ar[nx][ny]=bq;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c8);
					}
					else
					if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
						b_ar[nx][ny]=bq;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						clearpos(nx,ny);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c8);
					}
					else{
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
					}
				}
				else{
					p = checkpiece(nx,i);
					if(p!=0){
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
						break;
					}
				}
			}
		}
		else
		if(ny<cury){
			for(i=cury-1;i>=ny;i--){
				if(i==ny){
					p = checkpiece(nx,i);
					if(p==0){
						b_ar[nx][ny]=bq;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c8);
					}
					else
					if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
						b_ar[nx][ny]=bq;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						clearpos(nx,ny);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c8);
					}
					else{
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
					}
				}
				else{
					p = checkpiece(nx,i);
					if(p!=0){
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
						break;
					}
				}
			}
		}
	}
	else
	if(cury==ny){
		if(nx>curx){
			for(i=curx+1;i<=nx;i++){
				if(i==nx){
					p = checkpiece(i,ny);
					if(p==0){
						b_ar[nx][ny]=bq;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c8);
					}
					else
					if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
						b_ar[nx][ny]=bq;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						clearpos(nx,ny);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c8);
					}
					else{
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
					}
				}
				else{
					p = checkpiece(i,ny);
					if(p!=0){
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
						break;
					}
				}
			}
		}
		else
		if(nx<curx){
			 for(i=curx-1;i>=nx;i--){
				if(i==nx){
					p = checkpiece(i,ny);
					if(p==0){
						b_ar[nx][ny]=bq;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c8);
					}
					else
					if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
						b_ar[nx][ny]=bq;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						clearpos(nx,ny);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c8);
					}
					else{
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
					}
				}
				else{
					p = checkpiece(i,ny);
					if(p!=0){
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
						break;
					}
				}
			}
		}
	}
	else
	if((nx>curx)&&(ny>cury)){
		for(i=1;i<=8;i++){
			if((nx==curx+i)&&(ny==cury+i)){
				p = checkpiece(nx,ny);
				if(p==0){
					b_ar[nx][ny]=bq;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);
					delay(500);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c8);
				}
				else
				if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
					b_ar[nx][ny]=bq;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);						delay(500);
					clearpos(nx,ny);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c8);
				}
				else{
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
				}
				break;
			}
			else{
				p = checkpiece(curx+i,cury+i);
				if(p!=0){
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
					break;
				}
			}
		}
	}
	else
	if((nx<curx)&&(ny<cury)){
		for(i=1;i<=8;i++){
			if((nx==curx-i)&&(ny==cury-i)){
				p = checkpiece(nx,ny);
				if(p==0){
					b_ar[nx][ny]=bq;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);
					delay(500);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c8);
				}
				else
				if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
					b_ar[nx][ny]=bq;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);						delay(500);
					clearpos(nx,ny);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c8);
				}
				else{
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
				}
				break;
			}
			else{
				p = checkpiece(curx-i,cury-i);
				if(p!=0){
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
					break;
				}
			}
		}
	}
	else
	if((nx>curx)&&(ny<cury)){
		for(i=1;i<=8;i++){
			if((curx+i==nx)&&(cury-i==ny)){
				p = checkpiece(nx,ny);
				if(p==0){
					b_ar[nx][ny]=bq;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);
					delay(500);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c8);
				}
				else
				if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
					b_ar[nx][ny]=bq;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);						delay(500);
					clearpos(nx,ny);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c8);
				}
				else{
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
				}
				break;
			}
			else{
				p = checkpiece(curx+i,cury-i);
				if(p!=0){
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
					break;
				}
			}
		}
	}
	else
	if((nx<curx)&&(ny>cury)){
		for(i=1;i<=8;i++){
			if((curx-i==nx)&&(cury+i==ny)){
				p = checkpiece(nx,ny);
				if(p==0){
					b_ar[nx][ny]=bq;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);
					delay(500);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c8);
				}
				else
				if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
					b_ar[nx][ny]=bq;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);						delay(500);
					clearpos(nx,ny);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c8);
				}
				else{
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
				}
				break;
			}
			else{
				p = checkpiece(curx-i,cury+i);
				if(p!=0){
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
					break;
				}
			}
		}
	}
	else{
		gotoxy(2,10);
		printf("INVALID MOVE!!");
		gotoxy(66,10);
		printf("INVALID MOVE!!");
		delay(500);
		gotoxy(2,10);
		printf("              ");
		gotoxy(66,10);
		printf("              ");
	}
}
/*Function to be called when the player chooses to move a white pawn
used to make sure the move is legal and if legal then changes things
on user screen and virtual board array
*/
void Wqueen(int curx, int cury, int nx, int ny){
	int i,p;
	if(curx==nx){
		if(ny>cury){
			for(i=cury+1;i<=ny;i++){
				if(i==ny){
					p = checkpiece(nx,i);
					if(p==0){
						b_ar[nx][ny]=wq;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c2);
					}
					else
					if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
						b_ar[nx][ny]=wq;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						clearpos(nx,ny);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c2);
					}
					else{
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
					}
				}
				else{
					p = checkpiece(nx,i);
					if(p!=0){
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
						break;
					}
				}
			}
		}
		else
		if(ny<cury){
			for(i=cury-1;i>=ny;i--){
				if(i==ny){
					p = checkpiece(nx,i);
					if(p==0){
						b_ar[nx][ny]=wq;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c2);
					}
					else
					if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
						b_ar[nx][ny]=wq;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						clearpos(nx,ny);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c2);
					}
					else{
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
					}
				}
				else{
					p = checkpiece(nx,i);
					if(p!=0){
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
						break;
					}
				}
			}
		}
	}
	else
	if(cury==ny){
		if(nx>curx){
			for(i=curx+1;i<=nx;i++){
				if(i==nx){
					p = checkpiece(i,ny);
					if(p==0){
						b_ar[nx][ny]=wq;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c2);
					}
					else
					if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
						b_ar[nx][ny]=wq;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						clearpos(nx,ny);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c2);
					}
					else{
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
					}
				}
				else{
					p = checkpiece(i,ny);
					if(p!=0){
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
						break;
					}
				}
			}
		}
		else
		if(nx<curx){
			 for(i=curx-1;i>=nx;i--){
				if(i==nx){
					p = checkpiece(i,ny);
					if(p==0){
						b_ar[nx][ny]=wq;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c2);
					}
					else
					if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
						b_ar[nx][ny]=wq;
						b_ar[curx][cury]=0;
						clearpos(curx,cury);
						delay(500);
						clearpos(nx,ny);
						gotoxy(getsx(ny),getsy(nx));
						printf("%s",c2);
					}
					else{
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
					}
				}
				else{
					p = checkpiece(i,ny);
					if(p!=0){
						gotoxy(2,10);
						printf("INVALID MOVE!!");
						gotoxy(66,10);
						printf("INVALID MOVE!!");
						delay(500);
						gotoxy(2,10);
						printf("              ");
						gotoxy(66,10);
						printf("              ");
						break;
					}
				}
			}
		}
	}
	else
	if((nx>curx)&&(ny>cury)){
		for(i=1;i<=8;i++){
			if((nx==curx+i)&&(ny==cury+i)){
				p = checkpiece(nx,ny);
				if(p==0){
					b_ar[nx][ny]=wq;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);
					delay(500);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c2);
				}
				else
				if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
					b_ar[nx][ny]=wq;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);						delay(500);
					clearpos(nx,ny);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c2);
				}
				else{
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
				}
				break;
			}
			else{
				p = checkpiece(curx+i,cury+i);
				if(p!=0){
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
					break;
				}
			}
		}
	}
	else
	if((nx<curx)&&(ny<cury)){
		for(i=1;i<=8;i++){
			if((nx==curx-i)&&(ny==cury-i)){
				p = checkpiece(nx,ny);
				if(p==0){
					b_ar[nx][ny]=wq;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);
					delay(500);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c2);
				}
				else
				if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
					b_ar[nx][ny]=wq;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);						delay(500);
					clearpos(nx,ny);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c2);
				}
				else{
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
				}
				break;
			}
			else{
				p = checkpiece(curx-i,cury-i);
				if(p!=0){
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
					break;
				}
			}
		}
	}
	else
	if((nx>curx)&&(ny<cury)){
		for(i=1;i<=8;i++){
			if((curx+i==nx)&&(cury-i==ny)){
				p = checkpiece(nx,ny);
				if(p==0){
					b_ar[nx][ny]=wq;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);
					delay(500);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c2);
				}
				else
				if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
					b_ar[nx][ny]=wq;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);						delay(500);
					clearpos(nx,ny);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c2);
				}
				else{
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
				}
				break;
			}
			else{
				p = checkpiece(curx+i,cury-i);
				if(p!=0){
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
					break;
				}
			}
		}
	}
	else
	if((nx<curx)&&(ny>cury)){
		for(i=1;i<=8;i++){
			if((curx-i==nx)&&(cury+i==ny)){
				p = checkpiece(nx,ny);
				if(p==0){
					b_ar[nx][ny]=wq;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);
					delay(500);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c2);
				}
				else
				if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
					b_ar[nx][ny]=wq;
					b_ar[curx][cury]=0;
					clearpos(curx,cury);						delay(500);
					clearpos(nx,ny);
					gotoxy(getsx(ny),getsy(nx));
					printf("%s",c2);
				}
				else{
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
				}
				break;
			}
			else{
				p = checkpiece(curx-i,cury+i);
				if(p!=0){
					gotoxy(2,10);
					printf("INVALID MOVE!!");
					gotoxy(66,10);
					printf("INVALID MOVE!!");
					delay(500);
					gotoxy(2,10);
					printf("              ");
					gotoxy(66,10);
					printf("              ");
					break;
				}
			}
		}
	}
	else{
		gotoxy(2,10);
		printf("INVALID MOVE!!");
		gotoxy(66,10);
		printf("INVALID MOVE!!");
		delay(500);
		gotoxy(2,10);
		printf("              ");
		gotoxy(66,10);
		printf("              ");
	}
}
/*Function to be called when the player chooses to move a black king
used to make sure the move is legal and if legal then changes things
on user screen and virtual board array
*/
void Bking(int curx, int cury, int nx, int ny){
	int p;
	if((nx==curx+1)&&(ny==cury)){
		p = checkpiece(nx,ny);
		if(p==0){
			b_ar[nx][ny]=bk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c7);
		}
		else
		if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
			b_ar[nx][ny]=bk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c7);
		}
	}
	else
	if((nx==curx-1)&&(ny==cury)){
		p = checkpiece(nx,ny);
		if(p==0){
			b_ar[nx][ny]=bk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c7);
		}
		else
		if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
			b_ar[nx][ny]=bk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c7);
		}
	}
	else
	if((nx==curx)&&(ny==cury+1)){
		p = checkpiece(nx,ny);
		if(p==0){
			b_ar[nx][ny]=bk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c7);
		}
		else
		if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
			b_ar[nx][ny]=bk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c7);
		}
	}
	else
	if((nx==curx)&&(ny==cury-1)){
		p = checkpiece(nx,ny);
		if(p==0){
			b_ar[nx][ny]=bk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c7);
		}
		else
		if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
			b_ar[nx][ny]=bk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c7);
		}
	}
	else
	if((nx==curx+1)&&(ny==cury+1)){
		p = checkpiece(nx,ny);
			if(p==0){
			b_ar[nx][ny]=bk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c7);
		}
		else
		if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
			b_ar[nx][ny]=bk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c7);
		}
	}
	else
	if((nx==curx+1)&&(ny==cury-1)){
		p = checkpiece(nx,ny);
		if(p==0){
			b_ar[nx][ny]=bk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c7);
		}
		else
		if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
			b_ar[nx][ny]=bk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c7);
		}
	}
	else
	if((nx==curx-1)&&(ny==cury+1)){
		p = checkpiece(nx,ny);
		if(p==0){
			b_ar[nx][ny]=bk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c7);
		}
		else
		if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
			b_ar[nx][ny]=bk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c7);
		}
	}
	else
	if((nx==curx-1)&&(ny==cury-1)){
		p = checkpiece(nx,ny);
		if(p==0){
			b_ar[nx][ny]=bk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c7);
		}
		else
		if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
			b_ar[nx][ny]=bk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c7);
		}
	}
	else{
		gotoxy(2,10);
		printf("INVALID MOVE!!");
		gotoxy(66,10);
		printf("INVALID MOVE!!");
		delay(500);
		gotoxy(2,10);
		printf("              ");
		gotoxy(66,10);
		printf("              ");
	}
}
/*Function to be called when the player chooses to move a white king
used to make sure the move is legal and if legal then changes things
on user screen and virtual board array
*/
void Wking(int curx, int cury, int nx, int ny){
	int p;
	if((nx==curx+1)&&(ny==cury)){
		p = checkpiece(nx,ny);
		if(p==0){
			b_ar[nx][ny]=wk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c1);
		}
		else
		if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
			b_ar[nx][ny]=wk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c1);
		}
	}
	else
	if((nx==curx-1)&&(ny==cury)){
		p = checkpiece(nx,ny);
		if(p==0){
			b_ar[nx][ny]=wk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c1);
		}
		else
		if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
			b_ar[nx][ny]=wk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c1);
		}
	}
	else
	if((nx==curx)&&(ny==cury+1)){
		p = checkpiece(nx,ny);
		if(p==0){
			b_ar[nx][ny]=wk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c1);
		}
		else
		if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
			b_ar[nx][ny]=wk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c1);
		}
	}
	else
	if((nx==curx)&&(ny==cury-1)){
		p = checkpiece(nx,ny);
		if(p==0){
			b_ar[nx][ny]=wk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c1);
		}
		else
		if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
			b_ar[nx][ny]=wk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c1);
		}
	}
	else
	if((nx==curx+1)&&(ny==cury+1)){
		p = checkpiece(nx,ny);
			if(p==0){
			b_ar[nx][ny]=wk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c1);
		}
		else
		if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
			b_ar[nx][ny]=wk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c1);
		}
	}
	else
	if((nx==curx+1)&&(ny==cury-1)){
		p = checkpiece(nx,ny);
		if(p==0){
			b_ar[nx][ny]=wk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c1);
		}
		else
		if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
			b_ar[nx][ny]=wk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c1);
		}
	}
	else
	if((nx==curx-1)&&(ny==cury+1)){
		p = checkpiece(nx,ny);
		if(p==0){
			b_ar[nx][ny]=wk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c1);
		}
		else
		if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
			b_ar[nx][ny]=wk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c1);
		}
	}
	else
	if((nx==curx-1)&&(ny==cury-1)){
		p = checkpiece(nx,ny);
		if(p==0){
			b_ar[nx][ny]=wk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c1);
		}
		else
		if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
			b_ar[nx][ny]=wk;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c1);
		}
	}
	else{
		gotoxy(2,10);
		printf("INVALID MOVE!!");
		gotoxy(66,10);
		printf("INVALID MOVE!!");
		delay(500);
		gotoxy(2,10);
		printf("              ");
		gotoxy(66,10);
		printf("              ");
	}
}
/*Function to be called when the player chooses to move a black knight
used to make sure the move is legal and if legal then changes things
on user screen and virtual board array
*/
void Bknight(int curx, int cury, int nx, int ny){
	int p;
	if(((nx==curx-2)&&(ny==cury+1))||((nx==curx+2)&&(ny==cury+1))){
		p = checkpiece(nx,ny);
		if(p==0){
			b_ar[nx][ny]=bkn;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c10);
		}
		else
		if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
			b_ar[nx][ny]=bkn;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c10);
		}
	}
	else
	if(((nx==curx-2)&&(ny==cury-1))||((nx==curx+2)&&(ny==cury-1))){
		p = checkpiece(nx,ny);
		if(p==0){
			b_ar[nx][ny]=bkn;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c10);
		}
		else
		if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
			b_ar[nx][ny]=bkn;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c10);
		}
	}
	else
	if(((ny==cury-2)&&(nx==curx-1))||((ny==cury+2)&&(nx==curx-1))){
		p = checkpiece(nx,ny);
		if(p==0){
			b_ar[nx][ny]=bkn;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c10);
		}
		else
		if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
			b_ar[nx][ny]=bkn;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c10);
		}
	}
	else
	if(((ny==cury-2)&&(nx==curx+1))||((ny==cury+2)&&(nx==curx+1))){
		p = checkpiece(nx,ny);
		if(p==0){
			b_ar[nx][ny]=bkn;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c10);
		}
		else
		if((p==wp)||(p==wr)||(p==wkn)||(p==wb)||(p==wq)||(p==wk)){
			b_ar[nx][ny]=bkn;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c10);
		}
	}
	else{
		gotoxy(2,10);
		printf("INVALID MOVE!!");
		gotoxy(66,10);
		printf("INVALID MOVE!!");
		delay(500);
		gotoxy(2,10);
		printf("              ");
		gotoxy(66,10);
		printf("              ");
	}
}
/*Function to be called when the player chooses to move a white knight
used to make sure the move is legal and if legal then changes things
on user screen and virtual board array
*/
void Wknight(int curx, int cury, int nx, int ny){
	int p;
	if(((nx==curx-2)&&(ny==cury+1))||((nx==curx+2)&&(ny==cury+1))){
		p = checkpiece(nx,ny);
		if(p==0){
			b_ar[nx][ny]=wkn;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c4);
		}
		else
		if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
			b_ar[nx][ny]=wkn;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c4);
		}
	}
	else
	if(((nx==curx-2)&&(ny==cury-1))||((nx==curx+2)&&(ny==cury-1))){
		p = checkpiece(nx,ny);
		if(p==0){
			b_ar[nx][ny]=wkn;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c4);
		}
		else
		if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
			b_ar[nx][ny]=wkn;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c4);
		}
	}
	else
	if(((ny==cury-2)&&(nx==curx-1))||((ny==cury+2)&&(nx==curx-1))){
		p = checkpiece(nx,ny);
		if(p==0){
			b_ar[nx][ny]=wkn;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c4);
		}
		else
		if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
			b_ar[nx][ny]=wkn;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c4);
		}
	}
	else
	if(((ny==cury-2)&&(nx==curx+1))||((ny==cury+2)&&(nx==curx+1))){
		p = checkpiece(nx,ny);
		if(p==0){
			b_ar[nx][ny]=wkn;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);
			delay(500);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c4);
		}
		else
		if((p==bp)||(p==br)||(p==bkn)||(p==bb)||(p==bq)||(p==bk)){
			b_ar[nx][ny]=wkn;
			b_ar[curx][cury]=0;
			clearpos(curx,cury);						delay(500);
			clearpos(nx,ny);
			gotoxy(getsx(ny),getsy(nx));
			printf("%s",c4);
		}
	}
	else{
		gotoxy(2,10);
		printf("INVALID MOVE!!");
		gotoxy(66,10);
		printf("INVALID MOVE!!");
		delay(500);
		gotoxy(2,10);
		printf("              ");
		gotoxy(66,10);
		printf("              ");
	}
}
