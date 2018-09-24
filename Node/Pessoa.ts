import{Carro} from './Carro'

export class Pessoa{
    private nome: string
    private carroPreferido: string
    private carro: any

    constructor(nomePessoa: string, carroP: string){
        this.nome = nomePessoa
        this.carroPreferido = carroP
    }

    public dizerNome(): string{
        return this.nome
    }

    public dizerCarroPreferido(): string{
        return this.carroPreferido
    }

    public comprarCarro(carroComprado: Carro): void{
        this.carro = carroComprado
    }

    public dizerCarroQueTem(): Carro{
        return this.carro
    }
}