unsigned int digits_sum(unsigned int n) {  // функция возврата суммы цифр по числу
    return (n != 0) ? (n % 10) + digits_sum(n / 10) : 0;
}

vector<long long> groups(long long n_customers) { 
    vector<long long> ans(9999999); // в ячейке под номером i будет лежать количество вхождений 
    for (long long i = 0; i <= n_customers; ++i) {
        unsigned int sum1 = digits_sum(i);
        ++ans[sum1];
    }
    return ans;
}

vector<long long> groups2(long long n_customers, long long n_first_id) {
    vector<long long> ans1 = groups(n_customers);
    vector<long long> ans2 = groups(n_first_id);
    for (long long i = 0; i < ans1.size(); ++i) {
        ans1[i] -= ans2[i];
    }
    return ans1;
}
