
import java.util.Scanner;

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

	

}

public class Matrix{
	public static void main (String[] args){
		MatrixDinamica matriz = new MatrixDinamica(5, 5);
	}

}
