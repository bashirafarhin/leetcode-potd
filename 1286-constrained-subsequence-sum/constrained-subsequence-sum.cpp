class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);       // Создаем массив dp для хранения максимальных сумм подпоследовательностей
        deque<int> dq;           // Создаем двустороннюю очередь для удобного обновления диапазона окна
        int max_sum = INT_MIN;   // Инициализируем переменную для хранения максимальной суммы
        for (int i = 0; i < n; ++i) {
            // Убираем элементы из начала очереди, которые выходят за пределы диапазона k
            while (!dq.empty() && dq.front() < i - k) {
                dq.pop_front();
            }
            // Инициализируем dp[i] максимумом между текущим элементом и 0
            dp[i] = max(nums[i], dp[i]);
            // Если очередь не пуста, обновляем dp[i] с учетом суммы с предыдущим элементом
            if (!dq.empty()) {
                dp[i] = max(dp[i], dp[dq.front()] + nums[i]);
            }
            // Удаляем элементы из конца очереди, которые не могут улучшить текущую сумму
            while (!dq.empty() && dp[i] >= dp[dq.back()]) {
                dq.pop_back();
            }
            // Добавляем текущий индекс в очередь
            dq.push_back(i);
            // Обновляем максимальную сумму
            max_sum = max(max_sum, dp[i]);
        }
        // Обрабатываем случай, когда все элементы в массиве отрицательные
        if (max_sum == 0) {
            max_sum = *max_element(nums.begin(), nums.end());
        }
        return max_sum;
    }
};