from judging.judge_utils import judge_program_subtasks

subtasks = [
    (1, '')
]

def judge(their_answer, language):
    return judge_program_subtasks(__file__, their_answer, language, subtasks)
