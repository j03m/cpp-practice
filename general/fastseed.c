int main(){
           unsigned long int token = 7063571036830433281;
           int seed[2];
           printf("j03m - token: %llu\n", token);
           memcpy(seed, &token, sizeof(token));
           printf("j03m - seeds: [%d][%d]\n", seed[0], seed[1]);
           printf("%08x%08x", seed[0], seed[1]);
}