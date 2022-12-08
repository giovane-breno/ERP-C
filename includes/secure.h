/**
 * Criptografa uma string.
 * Adiciona 3 valores da tabela ASCII em cada caractere.
 *  
 * @param str deve ser uma string.
 * @return variavel criptografada.
 */
char *encrypt(char str[256])
{
    for (int i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] + 3; // Adiciona 3 na tabela ASCII.
    return str;
}

/**
 * Descriptografa uma string.
 * Subtrai 3 valores da tabela ASCII em cada caractere.
 *  
 * @param str deve ser uma string.
 * @return str descriptografada
 */
char *decrypt(char str[256])
{
    for (int i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] - 3; // Reduz 3 na tabela ASCII.
    return str;
}