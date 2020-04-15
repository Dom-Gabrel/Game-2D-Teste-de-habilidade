/*
  Projeto para o laboratório de Computação I ( LABORATÓRIO DE COMPUTAÇÃO I (AA783)), pela Universidade Federal Rural do Rio de Janeiro
Alunos: Célio dos Santos, Gabriel A. L. da Conceição, Francisco Sancas
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <string>
#define MASK 255, 255, 255;
#define FRAMES_PER_SECOND = 20;


typedef enum
{
  FALSE,
  TRUE
} boolean;


struct posicao{
	int x;
	int y;
};


 int checarTela(SDL_Surface *screen)
{
   if(screen == NULL) 
    {
      printf( "Error ao entrar em modo grafico: %s\n", SDL_GetError() );
      SDL_Quit();
      return -1;
   }
}


 int checarVideo()
{
   // inicializando sistema de video

   if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
      printf("Não se pode inicializar SDL: %s\n", SDL_GetError());
      exit(1);
   }
}


 int main()
{
   Mix_Chunk* effect1;
   Mix_Chunk* effect2;
   Mix_Music* music;
   Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
   music = Mix_LoadMUS("sons/musica.wav");
   effect1 = Mix_LoadWAV("sons/soco.wav");
   effect2 = Mix_LoadWAV("sons/chute.wav");
   Mix_PlayMusic(music, -1);
   TTF_Init();
   // declarando variaveis
   TTF_Font *fontAplic;
   fontAplic = TTF_OpenFont("fontes/FineCollege.ttf", 26);
   SDL_Surface *screen;
   SDL_Color colorChrono = {255, 255, 255};
   SDL_Surface *chrono;
   SDL_Event event;
   SDL_Rect posicao;
   SDL_Rect rectInimigo;
   SDL_Rect rectInimigo2;
   SDL_Rect rectInimigo3;
   SDL_Rect chronoPosicao;
   SDL_Rect abarra;
   SDL_Rect bbarra;
   Uint8* teclas; 
   Uint32 red, green, blue;

/*
=================== Load das imagens PNG ==================
*/
   SDL_Surface* fundo = IMG_Load("ata/fundo001.png");
	printf("IMG_Load: %s\n", IMG_GetError());
   SDL_Surface* jogador = IMG_Load("ata/warrior.png");
	printf("IMG_Load: %s\n", IMG_GetError());
   SDL_Surface* inimigo = IMG_Load("ata/Lord_Bills.png");
        printf("IMG_Load: %s\n", IMG_GetError());
  SDL_Surface* inimigo2 = IMG_Load("ata/bola009.png");
        printf("IMG_Load: %s\n", IMG_GetError());
  SDL_Surface* inimigo3 = IMG_Load("ata/bola012.png");
        printf("IMG_Load: %s\n", IMG_GetError());
  
SDL_Surface *barraA1 = IMG_Load("barras/barra001a.png");
SDL_Surface *barraA2 = IMG_Load("barras/barra002a.png");
SDL_Surface *barraA3 = IMG_Load("barras/barra003a.png");
SDL_Surface *barraA4 = IMG_Load("barras/barra004a.png");
SDL_Surface *barraA5 = IMG_Load("barras/barra005a.png");
SDL_Surface *barraA6 = IMG_Load("barras/barra006a.png");
SDL_Surface *barraA7 = IMG_Load("barras/barra007a.png");
SDL_Surface *barraA8 = IMG_Load("barras/barra008a.png");
SDL_Surface *barraA9 = IMG_Load("barras/barra009a.png");
SDL_Surface *barraA10 = IMG_Load("barras/barra010a.png");
SDL_Surface *barraA11 = IMG_Load("barras/barra011a.png");
SDL_Surface *barraA12 = IMG_Load("barras/barra012a.png");
SDL_Surface *barraA13 = IMG_Load("barras/barra013a.png");
SDL_Surface *aux1 = barraA1;


SDL_Surface *barraB1 = IMG_Load("barras/barra001b.png");
SDL_Surface *barraB2 = IMG_Load("barras/barra002b.png");
SDL_Surface *barraB3 = IMG_Load("barras/barra003b.png");
SDL_Surface *barraB4 = IMG_Load("barras/barra004b.png");
SDL_Surface *barraB5 = IMG_Load("barras/barra005b.png");
SDL_Surface *barraB6 = IMG_Load("barras/barra006b.png");
SDL_Surface *barraB7 = IMG_Load("barras/barra007b.png");
SDL_Surface *barraB8 = IMG_Load("barras/barra008b.png");
SDL_Surface *barraB9 = IMG_Load("barras/barra009b.png");
SDL_Surface *barraB10 = IMG_Load("barras/barra010b.png");
SDL_Surface *barraB11 = IMG_Load("barras/barra011b.png");
SDL_Surface *barraB12 = IMG_Load("barras/barra012b.png");
SDL_Surface *barraB13 = IMG_Load("barras/barra013b.png");
SDL_Surface *aux2 = barraB1;

	
/*
===========================================================
*/  
   struct posicao *posicoesInimigo3;
   struct posicao *posicoesInimigo2;
   struct posicao *posicoesInimigo;

   int terminar = 0;   
   int numeroInimigo = 1;
   int numeroInimigo2 = 1;
   int numeroInimigo3 = 1;
   int posicaoJogadorX = 50, posicaoJogadorY = 275;
   int abarraBarraAX = 50, abarraBarraAY = 20;
   int bbarraBarraBX = 370, bbarraBarraBY = 20;
   char timeText[20];
   int i,j;
   int tempo = clock();
   int vida=12, aux[13] = {1,2,3,4,5,6,7,8,9,10,11,12};
   int vida2=12, aux23[13] = {1,2,3,4,5,6,7,8,9,10,11,12};


   //setando posicao inicial do jogador na tela
   posicao.x = 50;
   posicao.y = 290;

   rectInimigo.w = 118;
   rectInimigo.h = 247;
   rectInimigo2.w = 80;
   rectInimigo2.h = 80;
   rectInimigo3.w = 120;
   rectInimigo3.h = 120;
   // setando posicao inicial do inimigo na tela
   rectInimigo.x = 520;
   rectInimigo.y = 60;
   rectInimigo2.x > 0;
   rectInimigo2.y = 150;
   rectInimigo3.x > 0;
   rectInimigo3.y = 150;
   chronoPosicao.x = 300;
   chronoPosicao.y = 50;
   //Posição fixa das barras
   abarra.x = 400;
   abarra.y = 255;
   bbarra.x = 700;
   bbarra.y = 255;
   // setando tamanho de tela
   screen = SDL_SetVideoMode( 700, 550, 24, SDL_HWSURFACE );
   checarTela(screen);
   checarVideo();
   SDL_WM_SetCaption("AA_Comp_I",NULL);

   // loop do jogo

   while(!terminar)
   {
/*
================= VARIAVEL PARA POSICAO =================
*/
    posicao.x=posicaoJogadorX;
    posicao.y=posicaoJogadorY;
    abarra.x=abarraBarraAX;
    abarra.y=abarraBarraAY;
    bbarra.x=bbarraBarraBX;
    bbarra.y=bbarraBarraBY;  	                       
/*
=========================================================
*/
     

/*
============================== CONTROLE DE TECLAS ===============================
*/
   while ( SDL_PollEvent(&event) ) 
     {
      if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
       {
         terminar = 1;  
       } 
     }


	teclas = SDL_GetKeyState(NULL);

      if (teclas[SDLK_DOWN]) 
       { 
	 posicaoJogadorY += 10; jogador = IMG_Load("ata/goku.png");
       }

      if (teclas[SDLK_UP]) 
       {
	 posicaoJogadorY -= 10; jogador = IMG_Load("ata/goku2.png");
       }

      if (teclas[SDLK_RIGHT]) 
       { 
	 posicaoJogadorX += 10; jogador = IMG_Load("ata/warrior.png");
       }

      if (teclas[SDLK_LEFT]) 
       { 
	 posicaoJogadorX -= 10; jogador = IMG_Load("ata/warrior2.png");
       } 


      if (teclas[SDLK_a] != 0) 
       { 
	 Mix_PlayChannel(-1, effect2, 0);
       }

      if (teclas[SDLK_s] != 0) 
       { 
	 Mix_PlayChannel(-1, effect1, 0);
       } 


      //Move o jogador para esquerda ou direita
      posicao.x += 10;

      //Move o jogador para cima ou para baixo
      posicao.y += 10;

/*
=================================================================================
*/
      // se posicao inimigo passar de 700, retorna a origem
      if(rectInimigo.x >= 700)
      {  
         rectInimigo.x = 0;
      }

      if(rectInimigo.x < 0)
      {
         rectInimigo.x = 699;
      }


      // se posicao inimigo2 (poder) passar de 700, retorna a origem
      if(rectInimigo2.x >= 700)
      {  
         rectInimigo2.x = 0;
      }

      if(rectInimigo2.x < 0)
      {
         rectInimigo2.x = 699;
      }

      // se posicao inimigo3 (poder) passar de 700, retorna a origem
      if(rectInimigo3.x >= 700)
      {  
         rectInimigo3.x = 0;
      }

      if(rectInimigo3.x < 0)
      {
         rectInimigo3.x = 699;
      }

     
     //==============================================================================

      if(rectInimigo.x > 0 && posicao.x > rectInimigo.x) //Algoritmos para virar inimigo 
      {
	inimigo = IMG_Load("ata/Bills2.png");
      }


      if(rectInimigo.x > 0 && posicao.x < rectInimigo.x) //Algoritmos para virar inimigo 
      {
	inimigo = IMG_Load("ata/Lord_Bills.png");
      }



      if(rectInimigo.x > 0 && posicao.x < rectInimigo.x) //Goku vira
      {
	jogador = IMG_Load("ata/warrior.png");
      }

      if(posicao.x > 0 && rectInimigo.x-85 < posicao.x) //Goku vira
      {
	jogador = IMG_Load("ata/warrior2.png");
      }

      if(rectInimigo.x > 0 && posicao.x < rectInimigo.x && teclas[SDLK_a]) 
      {
	jogador = IMG_Load("ata/warrior3.png");
      }

      if(rectInimigo.x > 0 && posicao.x > rectInimigo.x && teclas[SDLK_a]) 
      {
	jogador = IMG_Load("ata/warrior4.png"); 
      }

      if(rectInimigo.x > 0 && posicao.x > rectInimigo.x && teclas[SDLK_LSHIFT]) 
      {
	jogador = IMG_Load("ata/warrior5.png"); 
      }

      if(rectInimigo.x > 0 && posicao.x < rectInimigo.x && teclas[SDLK_LSHIFT]) 
      {
	jogador = IMG_Load("ata/warrior6.png"); 
      }

     if(rectInimigo.x > 0 && posicao.x > rectInimigo.x && teclas[SDLK_s]) 
      {
	jogador = IMG_Load("ata/warrior9.png"); 
      }

     if(rectInimigo.x > 0 && posicao.x < rectInimigo.x && teclas[SDLK_s]) 
      {
	jogador = IMG_Load("ata/warrior10.png"); 
      }

/*
========================= Colisão =========================
*/

	
      //Colisão do herói com a tela
      if(posicao.x >= 670) 
       {
    	posicao.x = 610; 
       }

      if(posicao.y > 275) 
       {
    	posicao.y = 324; 
       }

      if(posicao.y < 61)
       {
    	posicao.y = 60; 
       }


      //Colisão do inimigo com a tela
      if(rectInimigo.y > 275) 
       {
        rectInimigo.y = posicao.y;
    	//rectInimigo.y = 324; 
       }

      if(rectInimigo.y < 61)
       {
	rectInimigo.y = posicao.y;
    	//rectInimigo.y = 60; 
       }



    
/*
===========================================================
*/ 
    // andando com o inimigo na tela           
    rectInimigo.x = rectInimigo.x + 1;
    rectInimigo2.x = rectInimigo2.x + 2;
    rectInimigo3.x = rectInimigo3.x + 3;


     //Perseguição
     if(posicao.y < 275)
      {
         rectInimigo.y = rectInimigo.y - 3;
      }

     if(posicao.y > 275)
      {
	 rectInimigo.y = rectInimigo.y + 3;
      }

     if(posicao.y <= 275)
      {
	 rectInimigo2.y = rectInimigo2.y - 3;
      }

     if(posicao.y <= 275)
      {
	 rectInimigo3.y = rectInimigo3.y - 3;
      }

     if((posicao.y > 275) && (posicao.y < 549))
      {
	 rectInimigo2.y = rectInimigo2.y + 3;
      }

     if((posicao.y > 275) && (posicao.y < 549))
      {
	 rectInimigo3.y = rectInimigo3.y + 3;
      }

     if((posicao.y >= 275) && (posicao.y < 549))
      {
	 rectInimigo3.y = rectInimigo3.y + 3;
      }

      if(teclas[SDLK_LEFT] != 0)
       {
           rectInimigo.x = rectInimigo.x - 5;
       }


//
//golpes*******************************************
//


      //chutes
      if(((rectInimigo.x+300 == posicao.x) && (rectInimigo.y == posicao.y)) && (rectInimigo.x < posicao.x))
       {
         inimigo = IMG_Load("ata/Bills_chute.png");
       }

      if(((rectInimigo.x > 140) && (rectInimigo.x < 151)) && (rectInimigo.x < posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills_chute.png");
       }
	 

      if(((rectInimigo.x > 221) && (rectInimigo.x < 232)) && (rectInimigo.x < posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills_chute.png");
       }

      if(((rectInimigo.x > 302) && (rectInimigo.x < 313)) && (rectInimigo.x < posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills_chute.png");
       }

      if(((rectInimigo.x > 384) && (rectInimigo.x < 395)) && (rectInimigo.x < posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills_chute.png");
       }

      if(((rectInimigo.x > 465) && (rectInimigo.x < 476)) && (rectInimigo.x < posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills_chute.png");
       }

      if(((rectInimigo.x > 546) && (rectInimigo.x < 557)) && (rectInimigo.x < posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills_chute.png");
       }

      if(((rectInimigo.x > 627) && (rectInimigo.x < 638)) && (rectInimigo.x < posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills_chute.png");
       }

      if(((rectInimigo.x-300 == posicao.x) && (rectInimigo.y == posicao.y)) && (rectInimigo.x > posicao.x))
       {
         inimigo = IMG_Load("ata/Bills_chute2.png");
       }

      if(((rectInimigo.x > 151) && (rectInimigo.x < 162)) && (rectInimigo.x > posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills_chute2.png");
       }
	 

      if(((rectInimigo.x > 231) && (rectInimigo.x < 243)) && (rectInimigo.x > posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills_chute2.png");
       }

      if(((rectInimigo.x > 312) && (rectInimigo.x < 324)) && (rectInimigo.x > posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills_chute2.png");
       }

      if(((rectInimigo.x > 394) && (rectInimigo.x < 406)) && (rectInimigo.x > posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills_chute2.png");
       }

      if(((rectInimigo.x > 475) && (rectInimigo.x < 487)) && (rectInimigo.x > posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills_chute2.png");
       }

      if(((rectInimigo.x > 556) && (rectInimigo.x < 568)) && (rectInimigo.x > posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills_chute2.png");
       }

      if(((rectInimigo.x > 637) && (rectInimigo.x < 649)) && (rectInimigo.x > posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills_chute2.png");
       }

      //socos
      if(((rectInimigo.x+60 == posicao.x) && (rectInimigo.y == posicao.y)) && (rectInimigo.x < posicao.x))
       {
         inimigo = IMG_Load("ata/Bills4.png");
       }

      if(((rectInimigo.x > 150) && (rectInimigo.x < 161)) && (rectInimigo.x < posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills4.png");
       }
	 

      if(((rectInimigo.x > 231) && (rectInimigo.x < 242)) && (rectInimigo.x < posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills4.png");
       }

      if(((rectInimigo.x > 312) && (rectInimigo.x < 323)) && (rectInimigo.x < posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills4.png");
       }

      if(((rectInimigo.x > 394) && (rectInimigo.x < 405)) && (rectInimigo.x < posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills4.png");
       }

      if(((rectInimigo.x > 475) && (rectInimigo.x < 486)) && (rectInimigo.x < posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills4.png");
       }

      if(((rectInimigo.x > 556) && (rectInimigo.x < 567)) && (rectInimigo.x < posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills4.png");
       }

      if(((rectInimigo.x > 637) && (rectInimigo.x < 648)) && (rectInimigo.x < posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills4.png");
       }

      if(((rectInimigo.x-60 == posicao.x) && (rectInimigo.y == posicao.y)) && (rectInimigo.x < posicao.x))
       {
         inimigo = IMG_Load("ata/Bills4b.png");
       }

      if(((rectInimigo.x > 160) && (rectInimigo.x < 172)) && (rectInimigo.x > posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills4b.png");
       }
	 

      if(((rectInimigo.x > 241) && (rectInimigo.x < 253)) && (rectInimigo.x > posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills4b.png");
       }

      if(((rectInimigo.x > 322) && (rectInimigo.x < 333)) && (rectInimigo.x > posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills4b.png");
       }

      if(((rectInimigo.x > 404) && (rectInimigo.x < 416)) && (rectInimigo.x > posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills4b.png");
       }

      if(((rectInimigo.x > 485) && (rectInimigo.x < 497)) && (rectInimigo.x > posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills4b.png");
       }

      if(((rectInimigo.x > 566) && (rectInimigo.x < 577)) && (rectInimigo.x > posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills4b.png");
       }

      if(((rectInimigo.x > 647) && (rectInimigo.x < 659)) && (rectInimigo.x > posicao.x))
       {
	 inimigo = IMG_Load("ata/Bills4b.png");
       }


//Barras de vida
 if((((rectInimigo.x+50) == posicao.x && teclas[SDLK_LSHIFT] == 0) || (((rectInimigo.x-50) == posicao.x && teclas[SDLK_LSHIFT] == 0)) && (rectInimigo.y == posicao.y)))
  {
    vida = vida -1;

	if(aux[vida] == 12){
		
	aux1 = barraA2;
	
	}
	if(aux[vida] == 11){
		
	aux1 = barraA3;
	
	}
	if(aux[vida] == 10){
		
	aux1 = barraA4;
	
	}
	if(aux[vida] == 9){
		
	aux1 = barraA5;
	
	}
	if(aux[vida] == 8){
		
	aux1 = barraA6;
	
	}
	if(aux[vida] == 7){
		
	aux1 = barraA7;
	
	}
	if(aux[vida] == 6){
		
	aux1 = barraA8;
	
	}
	if(aux[vida] == 5){
		
	aux1 = barraA9;
	
	}
	if(aux[vida] == 4){
		
	aux1 = barraA10;
	
	}
	if(aux[vida] == 3){
		
	aux1 = barraA11;
	
	}
	if(aux[vida] == 2){
		
	aux1 = barraA12;
	
	}
	if(aux[vida] == 1){
		
	aux1 = barraA13;
	
	}

  }


/*

 if((((rectInimigo2.x+50) == posicao.x && teclas[SDLK_LSHIFT] == 0) || (((rectInimigo2.x-50) == posicao.x && teclas[SDLK_LSHIFT] == 0)) && (rectInimigo2.y < 275)))
  {
    vida = vida -1;

	if(aux[vida] == 12){
		
	aux1 = barraA2;
	
	}
	if(aux[vida] == 11){
		
	aux1 = barraA3;
	
	}
	if(aux[vida] == 10){
		
	aux1 = barraA4;
	
	}
	if(aux[vida] == 9){
		
	aux1 = barraA5;
	
	}
	if(aux[vida] == 8){
		
	aux1 = barraA6;
	
	}
	if(aux[vida] == 7){
		
	aux1 = barraA7;
	
	}
	if(aux[vida] == 6){
		
	aux1 = barraA8;
	
	}
	if(aux[vida] == 5){
		
	aux1 = barraA9;
	
	}
	if(aux[vida] == 4){
		
	aux1 = barraA10;
	
	}
	if(aux[vida] == 3){
		
	aux1 = barraA11;
	
	}
	if(aux[vida] == 2){
		
	aux1 = barraA12;
	
	}
	if(aux[vida] == 1){
		
	aux1 = barraA13;
	
	}

  }

*/




/*

 if((((rectInimigo3.x+50) == posicao.x && teclas[SDLK_LSHIFT] == 0) || (((rectInimigo3.x-50) == posicao.x && teclas[SDLK_LSHIFT] == 0)) && (rectInimigo3.y > 275)))
  {
    vida = vida -1;

	if(aux[vida] == 12){
		
	aux1 = barraA2;
	
	}
	if(aux[vida] == 11){
		
	aux1 = barraA3;
	
	}
	if(aux[vida] == 10){
		
	aux1 = barraA4;
	
	}
	if(aux[vida] == 9){
		
	aux1 = barraA5;
	
	}
	if(aux[vida] == 8){
		
	aux1 = barraA6;
	
	}
	if(aux[vida] == 7){
		
	aux1 = barraA7;
	
	}
	if(aux[vida] == 6){
		
	aux1 = barraA8;
	
	}
	if(aux[vida] == 5){
		
	aux1 = barraA9;
	
	}
	if(aux[vida] == 4){
		
	aux1 = barraA10;
	
	}
	if(aux[vida] == 3){
		
	aux1 = barraA11;
	
	}
	if(aux[vida] == 2){
		
	aux1 = barraA12;
	
	}
	if(aux[vida] == 1){
		
	aux1 = barraA13;
	
	}

  }

*/

       if(((rectInimigo3.x+50) == posicao.x) && (posicao.y <= 275))
	{
	   posicao.x += 80; //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	}


//
//golpes*******************************************
//


if((((posicao.x+10) == rectInimigo.x) || ((posicao.x+20) == rectInimigo.x) || ((posicao.x+30) == rectInimigo.x) || ((posicao.x+40) == rectInimigo.x) || ((posicao.x+50) == rectInimigo.x) || ((posicao.x+60) == rectInimigo.x) || ((posicao.x+70) == rectInimigo.x)) && ((teclas[SDLK_a] != 0) || teclas[SDLK_s] != 0) || (((posicao.x-10) == rectInimigo.x) || ((posicao.x-20) == rectInimigo.x) || ((posicao.x-30) == rectInimigo.x) || ((posicao.x-40) == rectInimigo.x) || ((posicao.x-50) == rectInimigo.x) || ((posicao.x-60) == rectInimigo.x) || ((posicao.x-70) == rectInimigo.x)) && ((teclas[SDLK_a] != 0) || teclas[SDLK_s] != 0))
  {
   
   vida2 = vida2 -1;

	if(aux23[vida2] == 12){
		
	aux2 = barraB2;
	
	}
	if(aux23[vida2] == 11){
		
	aux2 = barraB3;
	
	}
	if(aux23[vida2] == 10){
		
	aux2 = barraB4;
	
	}
	if(aux23[vida2] == 9){
		
	aux2 = barraB5;
	
	}
	if(aux23[vida2] == 8){
		
	aux2 = barraB6;
	
	}
	if(aux23[vida2] == 7){
		
	aux2 = barraB7;
	
	}
	if(aux23[vida2] == 6){
		
	aux2 = barraB8;
	
	}
	if(aux23[vida2] == 5){
		
	aux2 = barraB9;
	
	}
	if(aux23[vida2] == 4){
		
	aux2 = barraB10;
	
	}
	if(aux23[vida2] == 3){
		
	aux2 = barraB11;
	
	}
	if(aux23[vida2] == 2){
		
	aux2 = barraB12;
	
	}
	if(aux23[vida2] == 1){
		
	aux2 = barraB13;
	
	}



  }
   


    SDL_BlitSurface(fundo,NULL,screen,0); 
    //SDL_Delay(1000);
    SDL_BlitSurface(jogador, NULL, screen, &posicao); // blit jogador
    SDL_BlitSurface(inimigo, NULL, screen, &rectInimigo); //blit inimigo
    SDL_BlitSurface(inimigo2, NULL, screen, &rectInimigo2); //blit inimigo2
    SDL_BlitSurface(inimigo3, NULL, screen, &rectInimigo3); //blit inimigo3
    sprintf(timeText, "%d", 50 - SDL_GetTicks()/900);
/*if(10 - SDL_GetTicks()/900 == 0){
SDL_Quit();
}*/
    chrono = TTF_RenderText_Blended(fontAplic, timeText, colorChrono);
    SDL_BlitSurface(chrono, NULL, screen, &chronoPosicao);                        
    SDL_BlitSurface(aux1, NULL, screen, &abarra); 
    SDL_BlitSurface(aux2, NULL, screen, &bbarra);
    SDL_Flip(screen);
   }

    fprintf(stdout,"%d", SDL_GetTicks());
    SDL_Delay(60); // Espera 60 milissegundos 
    SDL_Quit();
    TTF_Quit(); //Encerra o ttf
    Mix_FreeChunk(effect1);
    Mix_FreeChunk(effect2);
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit(); // Fecha o SDL
    IMG_Quit();
   return 0;
}
