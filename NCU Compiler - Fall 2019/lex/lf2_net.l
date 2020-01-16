%{
%}

Soul_Punch (dd|aa)s
Upper_Cut 'ws
Skull_Blast 'ds+
Mirror_Image 'tst+
Soul_Bomb 'dt
Big_Bang 'wt

%%

{Soul_Punch} printf("Soul_Punch\n");
{Upper_Cut} printf("Upper_Cut\n");
{Skull_Blast} printf("Skull_Blast\n");
{Mirror_Image} printf("Mirror_Image\n");
{Soul_Bomb} printf("Soul_Bomb\n");
{Big_Bang} printf("Big_Bang\n");
.
\n


%%

int main(){
    yylex();
    return 0;
}
