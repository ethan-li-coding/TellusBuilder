#include "tellus_project.h"

TellusProject::TellusProject()
{
}

TellusProject::~TellusProject()
{
}

bool TellusProject::AddImages(const vector<string>& img_paths)
{
	new_images_.clear();
	for (auto& path : img_paths) {
		all_images_.emplace_back(path, all_images_.size());
		new_images_.emplace_back(all_images_.back());
	}
	return true;
}

const vector<Image>& TellusProject::GetAllImages()
{
	return all_images_;
}

const vector<Image>& TellusProject::GetNewAddingImages()
{
	// TODO: insert return statement here
	return new_images_;
}
