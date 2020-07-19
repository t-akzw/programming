select pref_name,
        sum( case when sex = '1' then population else 0 end ) as cnt_m,
        sum( case when sex = '2' then population else 0 end ) as cnt_f,
		sum( case when population > 100 then sex else -1 end ) as cnt_t
        from poptbl2
        group by pref_name;
