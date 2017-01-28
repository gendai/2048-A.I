void init_tables()
{
	init_left_table();
	std::cout << "Left table ready" << std::endl;
	init_right_table();
	std::cout << "Right table ready" << std::endl;
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
									c4t = 0;
								}
								if(c3t != 0 && c2t == 0)
								{
										if (c1t == 0)
										{
												c1t = c3t;
												c2t = c4t;
												c3t = 0;
												c4t = 0;
										}
										else
										{
											c2t = c3t;
											c3t = c4t;
											c4t = 0;
										}
										shift = 1;
								}
								if(c4t != 0 && c3t == 0)
								{
										if (c2t == 0)
										{
												if (c1t == 0)
												{
													c1t = c4t;
													c2t = 0;
													c3t = 0;
													c4t = 0;
												}
												else
												{
													c2t = c4t;
													c3t = 0;
													c4t = 0;
												}
										}
										else
										{
											c3t = c4t;
											c4t = 0;
										}
										shift = 1;
								}
						}
						uint16_t row_res[4];
						row_res[0] = c1t;
						row_res[1] = c2t;
						row_res[2] = c3t;
						row_res[3] = c4t;
						auto bt = 0;
						while (bt != 3)
						{
							if (row_res[bt] == row_res[bt + 1] && row_res[bt] != 0 && row_res[bt + 1] != 0)
							{
									row_res[bt] += 1;
									for (auto btemp = bt + 1; btemp < 3; ++btemp)
										row_res[btemp] = row_res[btemp + 1];
									row_res[3] = 0;
							}
							bt++;
						}
						uint16_t index = (c1 << 12) + (c2 << 8) + (c3 << 4) + c4;
						LEFT_TABLE[index] = (row_res[0] << 12) + (row_res[1] << 8) + (row_res[2] << 4) + row_res[3];
					}
			}
		}
	}
}

void init_right_table()
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
								if (c3t != 0 && c4t == 0)
								{
									c4t = c3t;
									c3t = c2t;
									c2t = c1t;
									c1t = 0;
									shift = 1;
								}
								if(c2t != 0 && c3t == 0)
								{
										if (c4t == 0)
										{
												c4t = c2t;
												c3t = c1t;
												c1t = 0;
												c2t = 0;
										}
										else
										{
											c3t = c2t;
											c2t = c1t;
											c1t = 0;
										}
										shift = 1;
								}
								if(c1t != 0 && c2t == 0)
								{
										if (c3t == 0)
										{
												if (c4t == 0)
												{
													c4t = c1t;
													c1t = 0;
													c2t = 0;
													c3t = 0;
												}
												else
												{
													c3t = c1t;
													c1t = 0;
													c2t = 0;
												}
										}
										else
										{
											c2t = c1t;
											c1t = 0;
										}
										shift = 1;
								}
						}
						uint16_t row_res[4];
						row_res[0] = c1t;
						row_res[1] = c2t;
						row_res[2] = c3t;
						row_res[3] = c4t;
						auto bt = 3;
						while (bt != 0)
						{
							if (row_res[bt] == row_res[bt - 1] && row_res[bt] != 0 && row_res[bt - 1] != 0)
							{
									row_res[bt] += 1;
									for (auto btemp = bt - 1; btemp > 0; --btemp)
										row_res[btemp] = row_res[btemp - 1];
									row_res[0] = 0;
							}
							bt--;
						}
						auto index = (c1 << 12) + (c2 << 8) + (c3 << 4) + c4;
						RIGHT_TABLE[index] = (row_res[0] << 12) + (row_res[1] << 8) + (row_res[2] << 4) + row_res[3];
					}
			}
		}
	}
}

uint16_t get_left_table(uint16_t value)
{
	return LEFT_TABLE[value];
}

uint16_t get_right_table(uint16_t value)
{
	return RIGHT_TABLE[value];
}
