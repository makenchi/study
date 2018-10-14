import{Carro} from './Carro'
import{ConcessionariaInterface} from './ConcessionarioInterface'

export class Concesionaria implements ConcessionariaInterface{
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

    public fornecerHoraDeFunc(): string{
        return 'De segunda a sexta das 08:00 as 19:00 e sábados das 09:00 as 14:00'
    }
}