//=====================================================================================================
//    Structs
//=====================================================================================================

//estrutura dos botões da tela inicial
typedef struct botao{
    ALLEGRO_BITMAP *ativado;
    ALLEGRO_BITMAP *desativado;
} botao;

//estrutura das telas do jogo
typedef struct telas{
    ALLEGRO_BITMAP *tela1;
    ALLEGRO_BITMAP *tela2;
} telas;

//estrutura de objetos das telas
typedef struct objeto{
    int ativo;
    int pos_x;
    int pos_y;
    int frame_ativo;
    char orientacao;
    ALLEGRO_BITMAP *imagem_ativa;
    ALLEGRO_BITMAP *imagem_cima[4];
    ALLEGRO_BITMAP *imagem_baixo[4];
    ALLEGRO_BITMAP *imagem_esquerda[4];
    ALLEGRO_BITMAP *imagem_direita[4];
    ALLEGRO_BITMAP *imagem_morto[4];
} objeto;


//estrutura dos objetos que possuem rotação e se comportam de forma a ignorar a movimentação comum
//PIOR NOME IMPOSSIVEL
typedef struct objeto_voador{
    int ativo;
    int pos_x;
    int pos_y;
    int pos_incx;
    int pos_incy;
    int destinox;
    int destinoy;
    int frame_ativo;
    float angulo;
    ALLEGRO_BITMAP *imagem_ativa;
    ALLEGRO_BITMAP *imagem[2];
    char teste;
} objeto_voador;


//=====================================================================================================
//    INICIALIZAÇÃO DAS VARIÁVEIS  GLOBAIS
//=====================================================================================================

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
ALLEGRO_BITMAP *botao_novo_exibir = NULL, *botao_ajuda_exibir = NULL, *botao_sair_exibir = NULL, *background_exibir = NULL, *background_exibir2 = NULL, *imagem_lanca = NULL, *fase1_entradas = NULL;
ALLEGRO_SAMPLE *sample[3];
ALLEGRO_SAMPLE_ID *ret_id;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_EVENT evento;
ALLEGRO_COLOR cor;
unsigned int clock1;

int tecla_pressionada = 0;
unsigned char r, g, b;

botao botao_novo, botao_ajuda, botao_sair;
telas background, background_tela1;
objeto personagem;
objeto_voador lanca;
objeto javali;

const int LARGURA_TELA = 1000;
const int ALTURA_TELA = 600;
#define PI 3.14159265
