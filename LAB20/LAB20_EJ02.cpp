{
	std::unique_ptr<double> d = std::make_unique<double>(1.0);
	std::unique_ptr<Point> pt = std::make_unique<Point>(1.0, 2.0);
	*d = 2.0;
	(*pt).X(3.0);
	(*pt).Y(3.0);

	pt->X(3.0);
	pt->Y(3.0);
}

