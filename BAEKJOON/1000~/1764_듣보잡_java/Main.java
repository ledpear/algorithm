import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int listen_size = Integer.parseInt(st.nextToken());
        int view_size = Integer.parseInt(st.nextToken());

        Set<String> set = new HashSet<>();

        for(int i = 0; i < listen_size; ++i)
        {
            String input = br.readLine();
            set.add(input);
        }

        List<String> list = new ArrayList<>();

        for(int i = 0; i < view_size; ++i)
        {
            String input = br.readLine();
            if(set.contains(input))
            {
                list.add(input);
            }
        }

        Collections.sort(list);
        System.out.println(list.size());

        for(int i = 0; i < list.size(); ++i)
        {
            System.out.println(list.get(i));
        }
    }
}