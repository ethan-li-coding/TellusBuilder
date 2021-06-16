#ifndef TELLUS_BUILDER_PROJECT_H
#define TELLUS_BUILDER_PROJECT_H

#include "tellus_types.h"

class TellusProject{
public:
	TellusProject();
	~TellusProject();

public:
	bool AddImages(const vector<string>& img_paths);

	const vector<Image>& GetAllImages();
	
	const vector<Image>& GetNewAddingImages();
private:
	/** vector of all images */
	vector<Image> all_images_;

	/** vector of new adding images */
	vector<Image> new_images_;
};

#endif