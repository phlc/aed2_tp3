/*
Ciencia da Computação - Pucminas
AEDs II
Pedro Henrique Lima Carvalho
Matricula: 651230
TP 3 - Q01
*/

/**
* Classe Personagem
*/
class Personagem {

//atributos
	private String nome;
	private int altura;
	private double peso;
	private String corDoCabelo;
	private String corDaPele;
	private String corDosOlhos;
	private String anoNascimento;
	private String genero;
	private String homeworld;

//construtores
	Personagem(String nome, int altura, double peso, String corDoCabelo,
		   String corDaPele, String corDosOlhos, String anoNascimento,
		   String genero, String homeworld){

		this.nome = nome;
		this.altura = altura;
		this.peso = peso;
		this.corDoCabelo = corDoCabelo;
		this.corDaPele = corDaPele;
		this.corDosOlhos = corDosOlhos;
		this.anoNascimento = anoNascimento;
		this.genero = genero;
		this.homeworld = homeworld;
	}

	Personagem(String endereco){
		Arq.openRead(endereco);
		String lida = Arq.readLine();
		Arq.close();
		
		String[] dados = parsePersonagem(lida);
	
		this.nome = dados[0];
		try{
			this.altura = Integer.parseInt(dados[1]);
		}
		catch(Exception e){
			this.altura = 0;
		}
		try{
			dados[2]=dados[2].replaceAll(",", "");
			this.peso = Double.parseDouble(dados[2]);
		}
		catch(Exception e){
			this.peso = 0;
		}
		this.corDoCabelo = dados[3];
		this.corDaPele = dados[4];
		this.corDosOlhos = dados[5];
		this.anoNascimento = dados[6];
		this.genero = dados[7];
		this.homeworld = dados[8];		
	}

//metodos
 //gets
	/*
	*getNome
	*@return String nome
	*/
	public String getNome(){
		return(this.nome);
	}

	/*
	*getAltura
	*@return int altura
	*/
	public int getAltura(){
		return(this.altura);
	}

	/*
	*getPeso
	*@return double peso
	*/
	public double getPeso(){
		return(this.peso);
	}
	
	/*
	*get corDoCabelo
	*@return String corDoCabelo 
	*/
	public String getCorDoCabelo(){
		return(this.corDoCabelo);
	}

	/*
	*getCorDaPele
	*@return String corDaPele
	*/
	public String getCorDaPele(){
		return(this.corDaPele);
	}

	/*
	*getCorDosOlhos
	*@return String corDosOlho
	*/
	public String getCorDosOlhos(){
		return(this.corDosOlhos);
	}

	/*
	*getAnoNascimento
	*@return String anoNascimento
	*/
	public String getAnoNascimento(){
		return(this.anoNascimento);
	}

	/*
	*getGenero
	*@return String genero
	*/
	public String getGenero(){
		return(this.genero);
	}

	/*
	*getHomeworld
	*@return String homeworld
	*/
	public String getHomeworld(){
		return(this.homeworld);
	}

//sets
	/*
	*setNome
	*@param String nome
	*/
	public void setNome(String nome){
		this.nome = nome;
	}	

	/*
	*setAltura
	*@param int altura
	*/
	public void setAlgura(int altura){
		this.altura = altura;
	}

	/*
	*setPeso
	*@param double peso
	*/
	public void setPeso(double peso){
		this.peso = peso;
	}

	/*
	*setCorDoCabelo
	*@param String corDoCabelo
	*/
	public void setCorDoCabelo (String corDoCabelo){
		this.corDoCabelo = corDoCabelo;
	}

	/*
	*setCorDaPele
	*@param String corDaPele
	*/
	public void setCorDaPelo(String corDaPelo){
		this.corDaPele = corDaPele;
	}

	/*
	*setCorDosOlhos
	*@param String corDosOlhos
	*/
	public void setCorDosOlhos(String corDosOlhos){
		this.corDosOlhos = corDosOlhos;
	}

	/*
	*setAnoNascimento
	*@param String anoNascimento
	*/
	public void setAnoNascimento(String anoNascimento){
		this.anoNascimento = anoNascimento;
	}

	/*
	*setGenero
	*@param String genero
	*/
	public void setGenero(String genero){
		this.genero = genero;
	}

	/*
	*setHomeworld
	*@param String homeworld
	*/
	public void setHomeworld(String homeworld){
		this.homeworld = homeworld;
	}

//clone
	/*
	*clone
	*@param Personagem
	*@return Personagem
	*/
	public Personagem clone(Personagem a){
		return (new Personagem(a.nome, a.altura, a.peso, a.corDoCabelo,
			a.corDaPele, a.corDosOlhos, a.anoNascimento, a.genero,
			a.homeworld));
	}

//imprimir
	/*
	*imprimir
	*/
	public void imprimir(){
		MyIO.print(" ## "+this.nome);
		MyIO.print(" ## "+this.altura);
		if (this.peso%1==0)
			MyIO.print(" ## "+(int)this.peso);
		else
			MyIO.print(" ## "+this.peso);
		MyIO.print(" ## "+this.corDoCabelo);
		MyIO.print(" ## "+this.corDaPele);
		MyIO.print(" ## "+this.corDosOlhos);
		MyIO.print(" ## "+this.anoNascimento);
		MyIO.print(" ## "+this.genero);
		MyIO.print(" ## "+this.homeworld);
		MyIO.println(" ## ");

	}

//ler
	/*
	*ler
	*@return
	*/
	public String ler(){
		return( " ## "+this.nome+" ## "+this.altura+" ## "+this.peso+
		       " ## "+this.corDoCabelo+" ## "+this.corDaPele+" ## "+
		       this.corDosOlhos+" ## "+this.anoNascimento+" ## "+this.genero+
		       " ## "+this.homeworld+" ## ");	
	}

//metodos estaticos publicos

 //isFim
	/**
	*isFim - verifica FIM
	*@param String
	*@return boolean
	*/
	public static boolean isFim(String s){
		return (s.equals("FIM"));
	}

 //toIso
	/**
	*toIso - muda o encoding de uma String para ISO
	*@param String UTF-8
	*@return String ISO
	*/
	public static String toIso(String s) throws Exception{
		return (new String(s.getBytes("UTF-8"), "ISO-8859-1"));
	}

 //toUtf
	/**
	*toUtf - muda o encoding de uma String para UTF-8
	*@param String ISO
	*@return String UTF-8
	*/
	public static String toUtf(String s) throws Exception{
		return(new String(s.getBytes("ISO-8859-1"), "UTF-8"));
	}

 //parsePersonagem
	/**
	*parsePersonagem - Separa os atributos do personagem de uma String
	*@param String
	*@return String[]
	*/
	private static String[] parsePersonagem(String s){
		String[] dados = new String[9];

		int init = 0;
		int end = -1;
		
		for (int i=0; i<9; i++){
			init = s.indexOf("\'", end+1)+1;
			end = s.indexOf("\'", init);
			init = s.indexOf("\'", end+1)+1;
			end = s.indexOf("\'", init);
			dados[i] = s.substring(init, end);
		}
		return (dados);
	}
}

/**
*Classe Celula
*/
class Celula{
 //atributos
	public Personagem elemento;
	public Celula prox;

 //construtores
	public Celula(Personagem p){
		this.elemento=p;
		this.prox=null;
	}
	
	public Celula(){
		this.elemento=null;
		this.prox=null;
	}
}

/**
*Classe Lista Flexivel
*/
class Lista{
 //atributos
	private Celula primeiro;
	private Celula ultimo;

 //contrutotres
	public Lista(){
		this.primeiro = new Celula();
		this.ultimo = primeiro;
	}

//inserir
	/**
	*inserirInicio - insere um elemento no inicio da lista
	*@param Personagem elemento
	*/
	public void inserirInicio(Personagem p){
		Celula tmp = new Celula(p);
		tmp.prox=primeiro.prox;
		primeiro.prox=tmp;
		if (primeiro==ultimo)
			ultimo=primeiro.prox;
		tmp=null;
	}

	/**
	*inserirFim - insere um elemento no fim da lista
	*@param Personagem elemento
	*/
	public void inserirFim(Personagem p){
		ultimo.prox = new Celula(p);
		ultimo=ultimo.prox;

	}

	/**
	*tamanho - retorna o tamanho da lista
	*@return tamanho int
	*/
	private int tamanho(){
		int resp = 0;
		for(Celula i=primeiro.prox; i!=null; i=i.prox){
			resp++;
		}
		return resp;
	}

	/**
	*inserir - insere um elemento em determinada posicao
	*@param Personagem elemento, int pos;
	*/
	public void inserir(Personagem p, int tamanho) throws Exception{
		int tamanho = tamanho();
		
		if (pos>tamanho || pos<0)
			throw new Exception ("Posicao Inexistente");
		else if (pos==tamanho)
			inserirFim(p);
		else if (pos==0)
			inserirInicio(p);
		else{
			Celula i=primeiro;
			for(int j=0; j<pos; j++, i=i.prox);
			
			Celula tmp = new Celula(p);
			tmp.prox = i.prox;
			i.prox=tmp;
			i=tmp=null;
		}

	}

 //remover
 
}

/**
*Classe Main
*/
public class TP03Q01{
	
	/**
	*Metodo main
	*/
	public static void main(String[] args) throws Exception{

		Personagem p;
		String input = MyIO.readLine();
		input = Personagem.toUtf(input);
		while(!Personagem.isFim(input)){
			p = new Personagem(input);
			p.imprimir();
			input = MyIO.readLine();
			input = Personagem.toUtf(input);
		}	

	}	

}
