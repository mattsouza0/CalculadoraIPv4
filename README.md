O programa incorpora as seguintes funcionalidades:

1. **Endereçamento com classes:**
   - **Entrada de dados:** Aceita um endereço IPv4, recusando entradas inválidas.
   - **Valores de saída:**
     - Classe do endereço IPv4 (A, B, C, D ou E).
     - Máscara na notação decimal e CIDR.
     - Número de hosts por rede (considerando descontos para o endereço de rede e de broadcast).
     - Endereço de rede (primeiro endereço do bloco).
     - Endereço de broadcast (último endereço do bloco).
     - Endereço IPv4 inicial utilizável por um host.
     - Endereço IPv4 final utilizável por um host.

2. **Endereçamento sem classes – máscara na notação decimal:**
   - **Entrada de dados:** Requer um endereço IPv4 (recusando entradas inválidas) e uma máscara na notação decimal (recusando máscaras inválidas).
   - **Valores de saída:**
     - Máscara na notação CIDR.
     - Número de hosts na sub-rede (considerando descontos para o endereço de rede e de broadcast).
     - Endereço de rede (primeiro endereço do bloco).
     - Endereço de broadcast (último endereço do bloco).
     - Endereço IPv4 inicial utilizável por um host.
     - Endereço IPv4 final utilizável por um host.

3. **Endereçamento sem classes – máscara na notação CIDR:**
   - **Entrada de dados:** Exige um endereço IPv4, recusando entradas inválidas.
   - 
