printf("Merge Sort\n");
        int interval = pos;
        for (int i = pos; i >= 1; i--)
        {
            flag = true;
            for (int j = 0; j * i < n; j++)
            {
                for (int u = i * j + 1; u < i * (j + 1) && u < n; u++)
                {
                    if (list2[u] < list2[u - 1])
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
            if (flag)
            {
                interval = i; 
                break;
            }
        }

        interval *= 2;
        for (int i = 0; i * interval < n; i++)
        {
            if((i + 1) * interval < n)
                sort(list2.begin() + i * interval, list2.begin() + (i + 1) * interval);
            else
                sort(list2.begin() + i * interval, list2.end());
        }

        for (int i = 0; i < n - 1; i++)
            printf("%d ", list2[i]);
        printf("%d\n", list2[n - 1]);