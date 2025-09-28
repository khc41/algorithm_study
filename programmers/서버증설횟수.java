class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        int[] returnServers = new int[24];
        int servers = 0;
        for(int i = 0; i < players.length; i++) {
            servers -= returnServers[i];
            int need = players[i] / m;
            if(servers < need) {
                int addServer = need - servers;
                servers += addServer;
                answer += addServer;
                if(i + k < players.length) {
                    returnServers[i + k] = addServer;
                }
            }
        }
        return answer;
    }
}