def join_middle(bound_by, tag_name):
    mid = len(bound_by) // 2
    return bound_by[:mid] + tag_name + bound_by[mid:]