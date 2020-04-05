/*
Ciencia da Computacao - Pucminas
AEDs II
Pedro Henrique Lima Carvalho
Matricula: 651230
TP 3 - Q05
*/

class Celula{
	//atributos
	Celula sup;
	Celula dir;
	Celula inf;
	Celula esq;
	int elemento;

	public Celula(int x){
		sup=dir=inf=esq=null;
		elemento = x;
	}

	public Celula(){
		this(0);
	}
}

class MatrixDinamica{
	//atributos
	Celula inicio;

	public MatrixDinamica(){
		inicio=null;
	}

	public MatrixDinamica(int linhas, int colunas){
		criar(linhas, colunas);
	}

	private Celula novaLinha(int colunas){
		Celula comeco = new Celula();
		Celula i = comeco;
		for(int j=1; j<colunas;j++){
			i.dir=new Celula();
			i.dir.esq = i;
			i=i.dir;
		}
		return comeco;			
	}

	private void conectarLinha (Celula comeco){
		Celula i;
		for(i=inicio; i.inf!=null; i=i.inf);

		while (i!=null && comeco!=null){
			i.inf=comeco;
			comeco.sup=i;

			i=i.dir;
			comeco=comeco.dir;
		}

	}

	private void criar(int linhas, int colunas){
		inicio = novaLinha(colunas);
		for(int i=1; i<linhas; i++){
			conectarLinha(novaLinha(colunas));
		}

	}

	public void mostrar(){
		Celula i = inicio;
		
		while(i!=null){
			for (Celula j=i; j!=null; j=j.dir){
				MyIO.print(i.elemento+" ");
			}
			MyIO.println("");	
			i=i.inf;
		}
	}

	public void mostrarPrincipal(){
		Celula i = inicio;

		while(i!=null){
			MyIO.print(i.elemento+" ");
			i=i.dir;
			if(i!=null)
				i=i.inf;
		}
		MyIO.println("");
	}	

	public void mostrarSecundaria(){
		Celula i = inicio;
		for(; i.dir!=null; i=i.dir);
	
		while(i!=null){
			MyIO.print(i.elemento+" ");
			i=i.esq;
			if(i!=null)
				i=i.inf;
		}
		MyIO.println("");
	}
}

public class TP03Q05{
	public static void main (String[] args){
		MatrixDinamica matriz = new MatrixDinamica(5, 5);
		
		matriz.mostrarPrincipal();
		matriz.mostrarSecundaria();
		matriz.mostrar();
	}

}
