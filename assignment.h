void rotation (void) ;
void drawStar(GLfloat cx, GLfloat cy, GLfloat mx, GLfloat my) ;
void drawSubmarine(void);
void init(void);
void outputKey(void);

static unsigned int base;

GLfloat PI = 3.14159265357f;
float xrot =0.0, yrot =0.0;
float xt =1.0,yt=1.0;
float height = 30;
float height2 =10;
float radius = 8;

float troMove =0;
float fishMove = 0;
float subMove = 0;
float aimMove =0;
float animationSpeed = 1;

float zoom =0.9;
bool xRotation = false;
bool yRotation = false;
bool animationEnabled = false;
int direction =0;
int aimDire =0;
int subDire =0;

