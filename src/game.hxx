void init_tables()
{
	init_left_table();
}

void init_left_table()
{
	for (auto c1 = 0; c1 < 16; ++c1)
	{
		for (auto c2 = 0; c2 < 16; ++c2)
		{
			for (auto c3 = 0; c3 < 16; ++c3)
			{
				for (auto c4 = 0; c4 < 16; ++c4)
				{
						auto c1t = c1;
						auto c2t = c2;
						auto c3t = c3;
						auto c4t = c4;
						int shift = 1;
						while (shift)
						{
								shift = 0;
								if (c2t != 0 && c1t == 0)
								{
									c1t = c2t;
									c2t = c3t;
									c3t = c4t;
									shift = 1;
								}
								if(c3t != 0 && c2t == 0)
								{
										if (c1t == 0)
										{
												c1t = c3t;
												c2t = c4t;
										}
										else
										{
											c2t = c3t;
											c3t = c4t;
										}
										shift = 1;
								}
								if(c4t != 0 && c3t == 0)
								{
										if (c2t == 0)
										{
												if (c1t == 0)
													c1t = c4t;
												else
													c2t = c4t;
										}
										else
											c3t = c4t;
										shift = 1;
								}
						}
						int row[4] = {c1t, c2t, c3t, c4t};
						int row_res[4];
						auto bt = 0;
						while (bt != 3)
						{
							if (row[bt] == row[bt + 1] && row[bt] != 0 && row[bt + 1] != 0)
							{
									row_res[bt] = row[bt] + 1;
									for (auto btemp = bt + 1; btemp < 3; ++btemp)
										row[btemp] = row[btemp + 1];
									row[3] = 0;
							}
							bt++;
						}
						auto index = (c1 << 12) + (c2 << 8) + (c3 << 4) + c4;
						LEFT_TABLE[index] = (row_res[0] << 12) + (row_res[1] << 8) + (row_res[2] << 4) + row_res[3];
				}
			}
		}
	}
}
