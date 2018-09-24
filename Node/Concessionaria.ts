import{Carro} from './Carro'

export class Concesionaria{
    private endereco: string
    private listaDeCarros: Array<Carro>

    constructor(endereco: string, listaCarros: Array<Carro>){
        this.endereco = endereco
        this.listaDeCarros = listaCarros
    }

    public fornecerEndereco(): string{
        return this.endereco
    }

    public mostrarListaDeCarros(): Array<Carro>{
        return this.listaDeCarros
    }
}