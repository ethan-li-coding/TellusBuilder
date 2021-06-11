#ifndef TELLUS_BUILDER_PROJECT_H
#define TELLUS_BUILDER_PROJECT_H

#include "tellus_types.h"

class TellusProject{
public:
	TellusProject();
	~TellusProject();

public:
	bool AddImage(string img_path);

	const vector<Image>& GetAllImages();
private:
	/** vector of all images */
	vector<Image> all_images_;
	
};

#endif